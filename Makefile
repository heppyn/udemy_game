CXX = g++
CPPFLAGS = -w -Wall -pedantic -Wextra -std=c++17
DEBUG = -g -fsanitize=address
RELEASE = -O3
IMPORTS = -I"./lib/lua" -L"./lib/lua" -llua -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
TARGETS = game game_debug

all: run

build_release:
	$(CXX) $(CPPFLAGS) $(RELEASE) $(IMPORTS) \
	./src/*.cpp \
	-o game;

build_debug:
	$(CXX) $(CPPFLAGS) $(DEBUG) $(IMPORTS) \
	./src/*.cpp \
	-o game_debug;

clean:
	rm -f $(TARGETS) *.o;

run: build_release
	./game;

debug: build_debug
	./game_debug;
