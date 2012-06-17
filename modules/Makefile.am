modulesdir = $(libdir)/$(PACKAGE)-$(LIBSKETCHBOARD_API_VERSION)/modules
modules_LTLIBRARIES=\
										libaddition.la

includedir=$(top_srcdir)/include
AM_CFLAGS=-I$(includedir) -std=gnu99 -Wall -Werror -DLIBDIR='"$(libdir)"' ${CFLAGS} ${GLIB_CFLAGS}
AM_LDFLAGS=-shrext "$(MODULE_EXT)" -avoid-version

libaddition_la_SOURCES=addition.c
