compiler = g++
output = bin/SilentEngine
maths = src/SilentMaths/*.hpp
renderer = src/SilentRenderer/*.cpp
entities = src/SilentEntities/*.cpp
system = src/SilentSystem/*.cpp
test = src/test.cpp
libs = -lSDL2 -lGLEW -lSDL2_image -lGL
src = $(renderer) $(entities) $(system) $(test)
flags = -Wall -std=c++11
all:
	$(compiler) $(flags) $(src) -o $(output) $(libs)
