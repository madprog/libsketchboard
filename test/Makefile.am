includedir=$(top_srcdir)/include
AM_CFLAGS=-I$(includedir) -std=gnu99 -Wall -Werror -DLIBDIR='"$(libdir)"' ${CFLAGS} ${GLIB_CFLAGS} ${DL_CFLAGS}
TESTS_LIBS=${LDFLAGS} ${GLIB_LIBS} ${DL_LIBS}

TESTS_ENVIRONMENT = SKETCHBOARD_MODULES_PATH=$(top_srcdir)/modules/.libs

check_PROGRAMS = \
                 check_sketch_management \
                 check_node_management \
                 check_node_transmission \
								 check_node_addition

check_sketch_management_SOURCES = check_sketch_management.c
check_sketch_management_LDADD = $(top_srcdir)/src/libsketchboard-@LIBSKETCHBOARD_API_VERSION@.la
check_sketch_management_LDFLAGS = ${TESTS_LIBS}

check_node_management_SOURCES = check_node_management.c
check_node_management_LDADD = $(top_srcdir)/src/libsketchboard-@LIBSKETCHBOARD_API_VERSION@.la
check_node_management_LDFLAGS = ${TESTS_LIBS}

check_node_transmission_SOURCES = check_node_transmission.c
check_node_transmission_LDADD = $(top_srcdir)/src/libsketchboard-@LIBSKETCHBOARD_API_VERSION@.la
check_node_transmission_LDFLAGS = ${TESTS_LIBS}

check_node_addition_SOURCES = check_node_addition.c
check_node_addition_LDADD = $(top_srcdir)/src/libsketchboard-@LIBSKETCHBOARD_API_VERSION@.la
check_node_addition_LDFLAGS = ${TESTS_LIBS}

TESTS = \
        check_sketch_management \
        check_node_management \
        check_node_transmission \
				check_node_addition
