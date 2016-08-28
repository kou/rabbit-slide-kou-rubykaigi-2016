CLEANFILES =

AM_CPPFLAGS =					\
	 -I$(top_builddir)			\
	 -I$(top_srcdir)

AM_CFLAGS =					\
	$(GLIB_CFLAGS)

lib_LTLIBRARIES =				\
	libgcalc.la

libgcalc_la_LIBADD =				\
	$(GLIB_LIBS)

libgcalc_la_SOURCES =				\
	gcalc.c					\
	gcalc.h

-include $(INTROSPECTION_MAKEFILE)
INTROSPECTION_GIRS =
INTROSPECTION_SCANNER_ARGS =
INTROSPECTION_COMPILER_ARGS =

if HAVE_INTROSPECTION
GCalc-1.0.gir: libgcalc.la
GCalc_1_0_gir_PACKAGES =
GCalc_1_0_gir_EXPORT_PACKAGES = gcalc
GCalc_1_0_gir_INCLUDES = GLib-2.0
GCalc_1_0_gir_CFLAGS =
GCalc_1_0_gir_LIBS = libgcalc.la
GCalc_1_0_gir_FILES = $(libgcalc_la_SOURCES)
GCalc_1_0_gir_SCANNERFLAGS =			\
	--identifier-prefix=GCalc		\
	--symbol-prefix=gcalc
INTROSPECTION_GIRS += GCalc-1.0.gir

girdir = $(datadir)/gir-1.0
gir_DATA = $(INTROSPECTION_GIRS)

typelibdir = $(libdir)/girepository-1.0
typelib_DATA = $(INTROSPECTION_GIRS:.gir=.typelib)

CLEANFILES +=					\
	$(gir_DATA)				\
	$(typelib_DATA)
endif
