--- libguile/gc_os_dep.c.orig	Mon Oct 20 01:22:19 2003
+++ libguile/gc_os_dep.c	Mon Oct 20 01:22:03 2003
@@ -93,6 +93,14 @@
 #    define OPENBSD
 #    define mach_type_known
 # endif
+# if defined(__FreeBSD__) && defined(__sparc__)
+#    define FREEBSD
+#    include <machine/frame.h>
+#    define ALIGNMENT 8
+#    define CPP_WORDSZ 64
+#    define ALIGN_DOUBLE
+#    define mach_type_known
+# endif
 # if defined(__NetBSD__) && defined(__powerpc__)
 #    define POWERPC
 #    define NETBSD
@@ -225,7 +233,16 @@
 #    define ARM32
 #    define mach_type_known
 # endif
-# if defined(__alpha) || defined(__alpha__)
+# if defined(__FreeBSD__) && defined(__ia64__)
+#    define FREEBSD
+#    define IA64
+#    define mach_type_known
+# endif
+# if defined(__FreeBSD__) && defined(__alpha__)
+#   define FREEBSD
+#   define ALPHA
+#   define mach_type_known
+# elif defined(__alpha) || defined(__alpha__)
 #   define ALPHA
 #   if !defined(LINUX)
 #     define OSF1	/* a.k.a Digital Unix */
@@ -1468,7 +1485,7 @@
 #   include <setjmp.h>
 #endif
 
-#ifdef FREEBSD
+#if defined(FREEBSD) && defined(I386)
 #  include <machine/trap.h>
 #endif
 
