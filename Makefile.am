SUBDIRS = src
EXTRA_DIST = contrib src/gnugetopt.h src/getopt.c src/getopt1.c test.sh rootsh.1
man_MANS = rootsh.1

dist-hook:
	for cvsdir in `find $(distdir) -name CVS -print`; do \
	  rm -rf $$cvsdir ; \
	done ;
