AUTOMAKE_OPTIONS = subdir-objects

lib_LTLIBRARIES=libsketchboard-@LIBSKETCHBOARD_API_VERSION@.la

libsketchboard_@LIBSKETCHBOARD_API_VERSION@_la_LDFLAGS=-version-info $(LIBSKETCHBOARD_SO_VERSION) ${LDFLAGS} ${GLIB_LIBS} ${DL_LIBS}

includedir=$(top_srcdir)/include
AM_CFLAGS=-I$(includedir) -std=gnu99 -Wall -Werror -DLIBDIR='"$(libdir)"' ${CFLAGS} ${GLIB_CFLAGS} ${DL_CFLAGS}

libsketchboard_@LIBSKETCHBOARD_API_VERSION@_la_SOURCES = \
				node.c \
        sketch.c
