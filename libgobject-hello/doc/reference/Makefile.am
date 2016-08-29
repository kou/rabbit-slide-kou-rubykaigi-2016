DOC_MODULE = ghello

DOC_MAIN_SGML_FILE = $(DOC_MODULE)-docs.sgml

DOC_SOURCE_DIR =				\
	$(top_srcdir)/ghello

SCAN_OPTIONS =						\
	--deprecated-guards="G_DISABLE_DEPRECATED"

MKDB_OPTIONS =					\
	--name-space=ghello

HFILE_GLOB =					\
	$(top_srcdir)/ghello/*.h

CFILE_GLOB =					\
	$(top_srcdir)/ghello/*.c

AM_CPPFLAGS =					\
	-I$(top_builddir)			\
	-I$(top_srcdir)

AM_CFLAGS =					\
	$(GLIB_CFLAGS)

GTKDOC_LIBS =					\
	$(top_builddir)/ghello/libghello.la	\
	$(GLIB_LIBS)

include $(srcdir)/gtk-doc.make

CLEANFILES +=					\
	$(DOC_MODULE)-sections.txt		\
	$(DOC_MODULE).types
