# Don't change!!!
CXX         =g++
UTCXXFLAGS  =-Werror -Wall -Wextra -Wno-format -Wold-style-cast -std=c++1z
CXXFLAGS    = $(UTCXXFLAGS) -fno-exceptions -fno-rtti
OUTPUT      =bin
UNITTEST_DIR=test

ECHO_COMPILE=echo "1. CC $(PROGNAME)"
ECHO_UT_COMPILE=echo "1. UTCC $(PROGNAME)"
SILENT_MKDIR=

#SUBMIT_URL=https://www.google.com

PROGNAME   =prog
PROGNAME_UT=utprog