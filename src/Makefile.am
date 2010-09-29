bin_PROGRAMS = opentuner
EXTRA_DIST = doxyfile.in

html-local: doxygen
doxygen:
	@if [ -z `which doxygen` ]; then echo "No Doxygen!"; else doxygen; fi
clean-local:
	rm -rf html

# noinst_PROGRAMS = 

headers = \
	application.h \
	config.h \
	configuration.h \
	controller.h \
	gui.h \
	log.h \
    unused.h

opentuner_SOURCES = \
	application.cpp \
	configuration.cpp \
	controller.cpp \
	gui.cpp \
	main.cpp \
	$(headers)

opentuner_CXXFLAGS = \
	$(CXXFLAGS) \
	$(BOOST_CPPFLAGS) \
	$(CLUTTER_CFLAGS) \
	$(LIBM_CXXFLAGS) \
	$(LIBTHREAD_CXXFLAGS) \
	$(STK_CXXFLAGS) \
	$(CXXFLAGS) \
	-DPIXMAPS_DIR=\"$(PIXMAPS_DIR)\"
 
opentuner_LDADD = \
	$(BOOST_FILESYSTEM_LIB) \
	$(BOOST_LDFLAGS) \
	$(BOOST_LIBS)  \
	$(BOOST_PROGRAM_OPTIONS_LIB) \
	$(BOOST_THREAD_LIB) \
	$(CLUTTER_LIBS) \
	$(LIBM_LIBS) \
	$(LIBTHREAD_LIBS) \
	$(LDFLAGS) \
	$(STK_LIBS)

