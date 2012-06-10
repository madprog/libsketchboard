includedir=$(top_srcdir)/include/sketchboard-$(LIBSKETCHBOARD_API_VERSION)
AM_CFLAGS=-I$(includedir) -std=gnu99 -Wall -Werror -pedantic-errors ${CFLAGS} \
          ${GLIB_CFLAGS}

check_PROGRAMS = \
                 check_sketch_management

check_sketch_management_SOURCES = check_sketch_management.c
check_sketch_management_LDADD = $(top_srcdir)/src/libsketchboard-@LIBSKETCHBOARD_API_VERSION@.la
check_sketch_management_LDFLAGS = ${LDFLAGS} \
				${GLIB_LIBS}

TESTS = \
        check_sketch_management
