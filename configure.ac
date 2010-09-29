#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.61)
AC_INIT(OPENTUNER, 0.1.0, alexandre@quessy.net)
AC_DEFINE([PACKAGE_URL],["http://alexandre.quessy.net"])
AC_CONFIG_HEADER([src/config.h])
AC_CONFIG_MACRO_DIR([m4]) # check for m4 macros in directory m4
AC_PROG_LIBTOOL
AM_INIT_AUTOMAKE()

# Check for C++ compiler
AC_PROG_CXX

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([arpa/inet.h stdlib.h string.h sys/ioctl.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST
PKG_PROG_PKG_CONFIG

AC_PROG_GCC_TRADITIONAL
AC_CHECK_FUNCS([inet_ntoa memset socket])

AC_CHECK_LIB([pthread],[pthread_exit],[AC_SUBST([LIBTHREAD_CXXFLAGS],["-lpthread"])])
AC_CHECK_LIB([m],[sin],[AC_SUBST([LIBM_CXXFLAGS],["-lm"])])

# STK
# TODO: print some message when configuring STK is OK
AC_LANG_PUSH(C++)
# save original flags
SAVED_LDFLAGS=$LDFLAGS
LDFLAGS="$LDFLAGS -lstk"
AC_LINK_IFELSE(
        [AC_LANG_PROGRAM([ #include <stk/RtMidi.h> ],
        [RtMidiIn input])],
        [AC_SUBST(STK_LIBS," -lstk -lrt -lm")],
        [AC_MSG_ERROR([libstk is not installed: alsa])])
LDFLAGS=$SAVED_LDFLAGS # restore them
AC_SUBST(STK_CXXFLAGS, "-D__LINUX_ALSA__ -D__UNIX_JACK__ -D__LITTLE_ENDIAN__")
AC_LANG_POP(C++)

# Clutter
PKG_CHECK_MODULES([CLUTTER], [clutter-1.0 >= 1.0], have_clutter=true, have_clutter=false)
if test "x${have_clutter}" = "xfalse" ; then
    AC_MSG_ERROR([missing package: libclutter-1.0-dev])
fi
AC_SUBST([CLUTTER_LIBS])
AC_SUBST([CLUTTER_CFLAGS])
# Clutter depends on:
# libjson-glib-dev and others


# BOOST
AX_BOOST_BASE([1.35])

AX_BOOST_PROGRAM_OPTIONS
if test "x${ax_cv_boost_program_options}" = "xno" ; then
	AC_MSG_ERROR([missing package: libboost-program-options-dev])
fi

AX_BOOST_FILESYSTEM
if test "x${ax_cv_boost_filesystem}" = "xno" ; then
	AC_MSG_ERROR([missing package: libboost-filesystem-dev])
fi

AX_BOOST_SYSTEM
if test "x${ax_cv_boost_system}" = "xno" ; then
	AC_MSG_ERROR([missing package: libboost-system-dev])
fi

# GNU help2man creates man pages from --help output; in many cases, this
# is sufficient, and obviates the need to maintain man pages separately.
# However, this means invoking executables, which we generally cannot do
# when cross-compiling, so we test to avoid that (the variable
# "cross_compiling" is set by AC_PROG_CC).
if test $cross_compiling = no; then
    AM_MISSING_PROG(HELP2MAN, help2man)
else
    HELP2MAN=:
fi

AS_AC_EXPAND(DATADIR, $datadir)
AC_MSG_NOTICE(Storing data files in $DATADIR)

PIXMAPS_DIR=$DATADIR/pixmaps
AC_SUBST(PIXMAPS_DIR)
AC_MSG_NOTICE(Storing pixmaps files in $PIXMAPS_DIR)

AC_SUBST(CXXFLAGS, " -O2 -Wall -Werror -Wextra -Wfatal-errors") 

AC_CONFIG_FILES([
    Makefile
    src/Makefile
    src/doxyfile
    man/Makefile
    tests/Makefile
    pixmaps/Makefile
    ])
AC_OUTPUT

