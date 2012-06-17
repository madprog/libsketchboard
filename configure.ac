#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([sketchboard], [1.0.0], [bugs@scengrafics.com])
AC_CONFIG_SRCDIR([src/sketch.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE
AM_SILENT_RULES([yes])

AC_SUBST([LIBSKETCHBOARD_SO_VERSION], [1:0:0])
AC_SUBST([LIBSKETCHBOARD_API_VERSION], [1.0])

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_MAKE_SET

# Checks for libraries.
LT_INIT([disable-static])

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
PKG_CHECK_MODULES([GLIB], [glib-2.0 >= 2.32], , [
	AC_CHECK_HEADERS([glib.h], , [AC_MSG_ERROR("glib header not found.")])
	AC_CHECK_LIB([glib-2.0], [g_malloc], , [AC_MSG_ERROR("Linking against glib failed.")])
])

AC_CHECK_HEADERS([dlfcn.h], [DL_CFLAGS=""], [AC_MSG_ERROR("dl header not found.")])
AC_CHECK_LIB([dl], [dlopen], [DL_LIBS="-ldl"], [AC_MSG_ERROR("Linking against dl failed.")])
AC_SUBST(DL_CFLAGS)
AC_SUBST(DL_LIBS)

PKG_CHECK_MODULES([GTK], [gtk+-2.0 >= 2.24], , [
	AC_CHECK_HEADERS([gtk/gtk.h], , [AC_MSG_ERROR("gtk+ header not found.")])
	AC_CHECK_LIB([gtk], [gtk_main], , [AC_MSG_ERROR("Linking against gtk+ failed.")])
])

PKG_CHECK_MODULES([GMODULE], [gmodule-2.0 >= 2.32], , [
	AC_CHECK_HEADERS([gmodule.h], , [AC_MSG_ERROR("gmodule header not found.")])
	AC_CHECK_LIB([gmodule-2.0], [gtk_main], , [AC_MSG_ERROR("Linking against gmodule failed.")])
])

AC_CONFIG_FILES(
		[Makefile]
		[include/Makefile]
		[modules/Makefile]
		[src/Makefile]
		[test/Makefile]
		[sketchboard-${LIBSKETCHBOARD_API_VERSION}.pc:sketchboard.pc.in]
		)

AH_TEMPLATE([DEFAULT_MODULES_PATH], [Place where libsketchboard will look for modules by default])
AC_DEFINE_UNQUOTED([DEFAULT_MODULES_PATH], [[LIBDIR "/${PACKAGE}-${LIBSKETCHBOARD_API_VERSION}/modules"]], [])

AC_SUBST([MODULE_EXT], [.mod])
AH_TEMPLATE([MODULE_EXT], [Extension of module files])
AC_DEFINE_UNQUOTED([MODULE_EXT], [["${MODULE_EXT}"]], [])

AC_OUTPUT
