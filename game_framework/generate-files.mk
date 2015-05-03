#!/usr/bin/make -f

# Make file for generating student templates - requires
# GNU Make, echo, sed and seq... oh yeah, and a shell.

# This defines the number of groups
#
NUMBER_OF_GROUPS ?= 150

#GROUPS     = $(shell seq -w $(NUMBER_OF_GROUPS))
GROUPS     = $(shell jot - 5 $(NUMBER_OF_GROUPS))
GROUPNAMES = $(addprefix T, $(GROUPS))
CPPFILES   = $(addsuffix .cpp, $(GROUPNAMES))
HFILES     = $(addsuffix .h,   $(GROUPNAMES))

ALLFILES   = $(CPPFILES) $(HFILES) group-defines.h group-headers.h group-case.c

all: $(ALLFILES)

T%.cpp: templates/base.cpp.in
	sed s/@GROUP@/$(notdir $(basename $@))/g $< > $@

T%.h: templates/base.h.in
	sed s/@GROUP@/$(notdir $(basename $@))/g $< > $@

group-defines.h group-headers.h group-case.c: $(HFILES) templates/inc-guard.h.in
	echo '/* Auto-generated file */' > group-defines.h.tmp
	echo '/* Auto-generated file */' > group-headers.h
	sed s/@HEADER@/GROUP_DEFINES/ < templates/inc-guard.h.in >>  group-defines.h.tmp
	sed s/@HEADER@/GROUP_HEADERS/ < templates/inc-guard.h.in >>  group-headers.h

	# Reset group-case.c
	echo > group-case.c

	set -e ; for G in $(GROUPS) ; do \
		echo "#define tT$$G $$G" >> group-defines.h.tmp ; \
		echo "#include \"T$$G.h\"" >> group-headers.h ; \
		echo "  case tT$$G: return new T$$G(smgr,driver,i,j,pg); break;" >> group-case.c ; \
	  done
	# group-defines.h has been generated with lines like:
	#   #define tT08 08
	# C/C++ reads the "08" as an (illegal) octal number,
	# so strip leading "0" from the numbers.
	sed 's/ 00*/ /' group-defines.h.tmp > group-defines.h
	echo "#endif" >> group-defines.h
	echo "#endif" >> group-headers.h
	rm -f group-defines.h.tmp

distclean:
	rm -f group-defines.h.tmp
	rm -f $(ALLFILES)

.PHONY: distclean

