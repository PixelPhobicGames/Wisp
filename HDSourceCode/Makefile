  UserOperatingSystem = $(shell uname)

  ifeq ($(OS),Windows_NT)
        PLATFORM = Windows
    else
		ifeq ($(UserOperatingSystem),Linux)
			PLATFORM = Linux
		endif
	endif

  ifeq ($(PLATFORM),Windows)
    CC = C:/raylib/mingw/bin/g++.exe
    exename ?= WispHD.exe
    CFLAGS  = -DWINDOWS_BUILD -s -O3 -static -Wall -Iexternal -DPLATFORM_DESKTOP -lopengl32 -lraylib -lgdi32 -lwinmm
  endif

  ifeq ($(PLATFORM),Linux)
    CC = g++
    exename ?= WispHD
    CFLAGS  = -DLINUX_BUILD -s -O3 -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
  endif

  all: $(TARGET)
	  $(CC) MysticEngine.cpp -o $(exename) $(CFLAGS)
