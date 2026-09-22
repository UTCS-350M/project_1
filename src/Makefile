CXX      := g++
CXXFLAGS := -std=gnu++17 -O2

.PHONY: all run clean

all: sim

sim: scheduler.cpp libsim.so
	$(CXX) $(CXXFLAGS) -o $@ scheduler.cpp -L. -lsim -Wl,-rpath,'$$ORIGIN'

run: sim
	./sim

clean:
	rm -f sim
