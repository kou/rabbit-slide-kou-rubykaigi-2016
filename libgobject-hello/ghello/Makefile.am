CLEANFILES =

AM_CPPFLAGS =					\
	 -I$(top_builddir)			\
	 -I$(top_srcdir)

AM_CFLAGS =					\
	$(GLIB_CFLAGS)

lib_LTLIBRARIES =				\
	libghello.la

libghello_la_LIBADD =				\
	$(GLIB_LIBS)

libghello_la_SOURCES =				\
	ghello.c				\
	ghello.h

-include $(INTROSPECTION_MAKEFILE)
INTROSPECTION_GIRS =
INTROSPECTION_SCANNER_ARGS =
INTROSPECTION_COMPILER_ARGS =

if HAVE_INTROSPECTION
Hello-1.0.gir: libghello.la
Hello_1_0_gir_PACKAGES =
Hello_1_0_gir_EXPORT_PACKAGES = ghello
Hello_1_0_gir_INCLUDES = GLib-2.0
Hello_1_0_gir_CFLAGS =
Hello_1_0_gir_LIBS = libghello.la
Hello_1_0_gir_FILES = $(libghello_la_SOURCES)
Hello_1_0_gir_SCANNERFLAGS =			\
	--identifier-prefix=G			\
	--symbol-prefix=g
INTROSPECTION_GIRS += Hello-1.0.gir

girdir = $(datadir)/gir-1.0
gir_DATA = $(INTROSPECTION_GIRS)

typelibdir = $(libdir)/girepository-1.0
typelib_DATA = $(INTROSPECTION_GIRS:.gir=.typelib)

CLEANFILES +=					\
	$(gir_DATA)				\
	$(typelib_DATA)
endif
