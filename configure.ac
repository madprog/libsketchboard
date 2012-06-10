#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([libsketchboard], [0.0.1], [bugs@scengrafics.com])
AC_CONFIG_SRCDIR([src/sketch.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE
AM_SILENT_RULES([yes])

AC_SUBST([LIBSKETCHBOARD_SO_VERSION], [1:0:0])
AC_SUBST([LIBSKETCHBOARD_API_VERSION], [1.0])
AC_SUBST([LIBSKETCHBOARD_LTAPI_VERSION], [1_0])

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_MAKE_SET

# Checks for libraries.
AM_PROG_LIBTOOL

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
PKG_CHECK_MODULES([GLIB], [glib-2.0 >= 2.32], , [
	AC_CHECK_HEADERS([glib.h], ,[AC_MSG_ERROR("glib header not found.")])
	AC_CHECK_LIB([glib-2.0], [g_list_append], , [AC_MSG_ERROR("Linking against glib failed.")])
])

PKG_CHECK_MODULES([GTK], [gtk+-2.0 >= 2.24], , [
	AC_CHECK_HEADERS([gtk/gtk.h], ,[AC_MSG_ERROR("gtk+ header not found.")])
	AC_CHECK_LIB([gtk], [gtk_main], , [AC_MSG_ERROR("Linking against gtk+ failed.")])
])

PKG_CHECK_MODULES([GMODULE], [gmodule-2.0 >= 2.32], , [
	AC_CHECK_HEADERS([gmodule.h], ,[AC_MSG_ERROR("gmodule header not found.")])
	AC_CHECK_LIB([gmodule-2.0], [gtk_main], , [AC_MSG_ERROR("Linking against gmodule failed.")])
])

AC_CONFIG_FILES(
		[Makefile]
		[src/Makefile]
		[test/Makefile]
		[sketchboard-${LIBSKETCHBOARD_API_VERSION}.pc:sketchboard.pc.in]
		)

#LIBS="$LIBS $GTK_LIBS $GMODULE_LIBS"
#CFLAGS="$CFLAGS $GTK_CFLAGS $GMODULE_CFLAGS"

AC_OUTPUT
