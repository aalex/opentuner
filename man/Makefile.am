man_MANS = opentuner.1 
EXTRA_DIST = $(man_MANS) man-opentuner.txt
MAINTAINERCLEANFILES = $(man_MANS)

# The man pages depend on the --help strings and the version number.
common_mandeps = $(top_srcdir)/configure.ac

# Depend on the source, not the binary; we don't need to regenerate the
# binary when any source file changes, only the main one.
# Use -o so that the `missing' program can infer the output file.
toonloop.1: $(top_srcdir)/src/application.cpp $(common_mandeps) $(top_srcdir)/man/man-opentuner.txt
	$(HELP2MAN) --include=man-opentuner.txt --name="The Opentuner musical tuner" --no-info $(top_builddir)/src/opentuner -o $@
