ACLOCAL_AMFLAGS=-Im4

pkgincludedir = $(includedir)/$(PACKAGE)-$(LIBSKETCHBOARD_API_VERSION)
libincludedir = $(libdir)/$(PACKAGE)-$(LIBSKETCHBOARD_API_VERSION)/include
pkgconfigdir = $(libdir)/pkgconfig

SUBDIRS=include src test

pkgconfig_DATA = sketchboard-@LIBSKETCHBOARD_API_VERSION@.pc
libinclude_HEADERS = config.h
