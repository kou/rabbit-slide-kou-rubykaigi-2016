DOC_MODULE = gcalc

DOC_MAIN_SGML_FILE = $(DOC_MODULE)-docs.sgml

DOC_SOURCE_DIR =				\
	$(top_srcdir)/gcalc

SCAN_OPTIONS =						\
	--deprecated-guards="SAMPLE_DISABLE_DEPRECATED"

MKDB_OPTIONS =					\
	--name-space=gcalc

HFILE_GLOB =					\
	$(top_srcdir)/gcalc/*.h

CFILE_GLOB =					\
	$(top_srcdir)/gcalc/*.c

AM_CPPFLAGS =					\
	-I$(top_builddir)			\
	-I$(top_srcdir)

AM_CFLAGS =					\
	$(GLIB_CFLAGS)

GTKDOC_LIBS =						\
	$(top_builddir)/gcalc/libgobject-calc.la	\
	$(GLIB_LIBS)

include $(srcdir)/gtk-doc.make

CLEANFILES +=					\
	$(DOC_MODULE)-sections.txt		\
	$(DOC_MODULE).types
