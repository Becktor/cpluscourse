# Makefile for Irrlicht Examples
# It's usually sufficient to change just the target name and source file list
# and be sure that CXX is set to a valid compiler
#
#
#
ENDING_SOURCE := cpp
ENDING_HEADER := h
Headers       := $(wildcard *.$(ENDING_HEADER))
Sources       := $(wildcard *.$(ENDING_SOURCE))
Objects       := $(patsubst %.$(ENDING_SOURCE),%.o,$(Sources))
#
# Name of the executable created (.exe will be added automatically if necessary)
Target := enigma3d
############################################
# List of source files
############################################
#Sources := $(wildcard *.cpp) # main.cpp game.cpp field.cpp `ls T*.cpp`
############################################
# List of header files
############################################
#Headers := $(wildcard *.h) #game.h field.h `ls T*.cpp`
# Path to Irrlicht directory, should contain include/ and lib/
IrrlichtHome := irrlicht-1.8.1
# only for mac:
LibIrr := $(IrrlichtHome)/lib/MacOSX/libIrrlicht.a
Arch := x86_64

# Path for the executable. Note that Irrlicht.dll should usually also be there for win32 systems
BinPath = .
# Name of the system, please choose one of
# win32, linux or mac (all lowercase!)
SYSTEM_NAME = mac

# general compiler settings (might need to be set when compiling the lib, too)
# preprocessor flags, e.g. defines and include paths
USERCPPFLAGS = -I/usr/include/irrlicht 
# compiler flags such as optimization flags
# -g is debug information (line numbers etc.)
USERCXXFLAGS = -g -O3 -ffast-math
#USERCXXFLAGS = -g -Wall
# linker flags such as additional libraries and link paths
USERLDFLAGS =

####
#no changes necessary below this line
####


CPPFLAGS = -I$(IrrlichtHome)/include -I/usr/X11R6/include $(USERCPPFLAGS)
CXXFLAGS = $(USERCXXFLAGS)
LDFLAGS = $(USERLDFLAGS)

#default target is Linux
all: all_$(SYSTEM_NAME)

# target specific settings
all_mac: LDFLAGS += $(LibIrr) -framework OpenGL -framework Cocoa -framework Carbon -framework IOKit
all_mac: CPPFLAGS += -fvisibility=hidden -arch $(Arch) 
all_linux all_win32 static_win32: LDFLAGS += -L$(IrrlichtHome)/lib/$(SYSTEM) -lIrrlicht
all_linux: LDFLAGS += -L/usr/X11R6/lib$(LIBSELECT) -lGL -lXxf86vm -lXext -lX11
all_linux clean_linux: SYSTEM=Linux
all_win32 clean_win32 static_win32: SYSTEM=Win32-gcc
all_win32 clean_win32 static_win32: SUF=.exe
static_win32: CPPFLAGS += -D_IRR_STATIC_LIB_
all_win32: LDFLAGS += -lopengl32 -lm
static_win32: LDFLAGS += -lgdi32 -lwinspool -lcomdlg32 -lole32 -loleaut32 -luuid -lodbc32 -lodbccp32 -lopengl32
# name of the binary - only valid for targets which set SYSTEM
DESTPATH = $(BinPath)/$(Target)$(SUF)

all_linux all_win32 static_win32: $(DESTPATH)

all_mac: $(Target).App/Contents/MacOS/$(Target)

.SUFFIXES: .cpp

.cpp.o:
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) -o $@ $< 

$(Target).App/Contents/MacOS/$(Target): $(Objects)
	$(warning Building...)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(Objects) -o temp $(LDFLAGS)
	lipo -create temp -output $(Target).App/Contents/MacOS/$(Target)

$(DESTPATH): $(Objects)
	$(warning Building...)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(Objects) -o $(DESTPATH) $(LDFLAGS)

clean: clean_linux clean_win32
	$(warning Cleaning...)

clean_linux clean_win32:
	@$(RM) $(DESTPATH) $(Objects)

.PHONY: all all_win32 static_win32 clean clean_linux clean_win32

#multilib handling
ifeq ($(HOSTTYPE), x86_64)
LIBSELECT=64
endif
#solaris real-time features
ifeq ($(HOSTTYPE), sun4)
LDFLAGS += -lrt
endif

