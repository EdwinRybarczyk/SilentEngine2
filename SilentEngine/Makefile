compiler = g++
output = bin/SilentEngine
maths = src/SilentMaths/*
renderer = src/SilentRenderer/*
entities = src/SilentEntities/*
system = src/SilentSystem/*
test = src/test.cpp
libs = -lSDL2 -lGL
src = $(maths) $(renderer) $(entities) $(system) $(test)
all:
	$(compiler) -Wall $(src) -o $(output) $(libs)
