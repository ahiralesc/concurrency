#
# Make file template
# 
# Author: Yorick Van Pelt
# 
# Updated by Adan Hirales <ahiralesc@gmail.com>
# 
# Last update: 10/09/2016
#
# See www.gnu.org/software/make 
#

ifdef VERBOSE
	Q = 
	E = @true
else
	Q = @
	E = @echo
endif

CFILES := $(shell find src -mindepth 1 -maxdepth 4 -name "*.c")
CXXFILES := $(shell find src -mindepth 1 -maxdepth 4 -name "*.cpp")

INFILES := $(CFILES) $(CXXFILES)

OBJFILES := $(CXXFILES:src/%.cpp=%) $(CFILES:src/%.c=%)
DEPFILES := $(CXXFILES:src/%.cpp=%) $(CFILES:src/%.c=%)
OFILES := $(OBJFILES:%=obj/%.o)

BINFILE = print_issues

COMMONFLAGS = -Wall -Wextra -pedantic
LDFLAGS = -pthread

ifdef DEBUG
	COMMONFLAGS := $(COMMONFLAGS) -g
endif

CFLAGS = $(COMMONFLAGS) --std=c99
CXXFLAGS = $(COMMONFLAGS) --std=c++0x
DEPDIR = deps

all: $(BINFILE)
ifeq ($(MAKECMDGOALS),)
-include Makefile.dep
endif
ifneq ($(filter-out clean, $(MAKECMDGOALS)),)
-include Makefile.dep
endif

CC = gcc
CXX = g++

-include Makefile.local

.PHONY: clean all depend
.SUFFIXES:
obj/%.o: src/%.c
	$(E) 'Compiling C code' $<
	$(Q)if [! -d 'dirname $@' ]; then mkdir -p 'dirname $@'; fi
	$(Q)$(CC) -o $@ -c $< $(CFLAGS)

obj/%.o: src/%.cpp
	$(E) 'Compiling Cpp code' $<
	$(Q)if [ ! -d `dirname $@` ]; then mkdir -p `dirname $@`; fi
	$(Q)$(CXX) -o $@ -c $< $(CXXFLAGS) -Iinclude

Makefile.dep: $(CFILES) $(CXXFILES)
	$(E) 'Dependencies'
	$(Q)for i in $(^); do $(CXX) $(CXXFLAGS) -Iinclude -MM "$${i}" -MT obj/`basename $${i%.*}`.o; done > $@

$(BINFILE): $(OFILES)
	$(E) 'Linking' $@
	$(Q)$(CXX) -o bin/$@ $(OFILES) $(LDFLAGS)

clean:
	$(E) 'Removing binaries'
	$(Q)rm -f $(BINFILE) obj/* Makefile.dep

# test:
#	$(E)Comiling C test code $@
#	$(Q)$(CC) -o $@ -c $< $(CFLAGS)
# 
# spikes:
# 	$(E)Compiling spikes
# 	$(Q)$(CC) -o $@ -c $< $(CFLAGS)
