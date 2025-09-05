CC = g++
CFLAGS = -Iinclude -Iexternal/include/SDL2
LDFLAGS = -Lexternal/include/SDL2 -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf
SOURCES = $(wildcard src/**/*.cpp) src/main.cpp

TARGET = main.exe

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET) $(LDFLAGS)

clean:
	del $(TARGET)
