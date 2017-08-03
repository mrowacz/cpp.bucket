CXX := g++
CXXFLAGS := -g -std=c++17

SRCS=$(wildcard *.cpp)
PRGS := $(patsubst %.cpp,%,$(SRCS))

all: output_dir $(PRGS)
	@echo "Compiled!"

output_dir:
	@mkdir -p ./output	
	
$(PRGS):
	echo "Compiling " $@
	$(CXX) $(CXXFLAGS) $@.cpp -o ./output/$@