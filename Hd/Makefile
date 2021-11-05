
  version ?= DEBUG
  UOS=$(shell uname)
  ifeq ($(OS),Windows_NT)
        PLATFORM = windows
    else
		ifeq ($(UOS),Linux)
			PLATFORM = linux
		endif
	endif
  ifeq ($(PLATFORM),windows)
    CC = C:/raylib/mingw/bin/g++.exe
    exename ?= Wisp.exe
    CFLAGS  = -s -O3 -static -Wall -Iexternal -DPLATFORM_DESKTOP -lopengl32 -lraylib -lgdi32 -lwinmm -D _TINYCONFIG 
  endif
  ifeq ($(PLATFORM),linux)
    CC = g++
    exename ?= Wisp
    CFLAGS  = -s -O3 -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -D _TINYCONFIG
  endif

  all: $(TARGET)
	  $(CC) MysticEngine.cpp -o $(exename) $(CFLAGS)
