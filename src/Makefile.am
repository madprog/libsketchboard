AUTOMAKE_OPTIONS = subdir-objects

lib_LTLIBRARIES=libsketchboard-@LIBSKETCHBOARD_API_VERSION@.la

libsketchboard_@LIBSKETCHBOARD_API_VERSION@_la_LDFLAGS=-version-info $(LIBSKETCHBOARD_SO_VERSION) ${LDFLAGS} \
        ${GLIB_LIBS}

includedir=$(top_srcdir)/include/sketchboard-$(LIBSKETCHBOARD_API_VERSION)
AM_CFLAGS=-I$(includedir) -std=gnu99 -Wall -Werror -pedantic-errors ${CFLAGS} \
          ${GLIB_CFLAGS}

library_includedir=$(includedir)/sketchboard-$(LIBSKETCHBOARD_API_VERSION)
library_include_HEADERS = \
                          $(includedir)/sketchboard.h \
                          $(includedir)/sketchboard/node.h \
                          $(includedir)/sketchboard/sketch.h
libsketchboard_@LIBSKETCHBOARD_API_VERSION@_la_SOURCES = \
				node.c \
        sketch.c
