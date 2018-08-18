CXX = g++ -Wall -pedantic
MAIN_BINARIES = $(basename $(wildcard *Main.cpp))
HEADERS = $(wildcard *.h)
OBJECTS = $(addsuffix .o, $(basename $(filter-out %Main.cpp %Test.cpp, $(wildcard *.cpp))))
LIBRARIES = -lsfml-graphics -lsfml-window -lsfml-system


.PRECIOUS: %.o
.SUFFIXES:
.PHONY: all compile test checkstyke

all: compile cleanout

compile: $(MAIN_BINARIES)

checkstyle:
	python3 /usr/local/lib/python2.7/dist-packages/cpplint.py --repository=. *.h *.cpp

clean:
	rm -f *.o
	rm -f $(MAIN_BINARIES)
	rm -f $(TEST_BINARIES)

cleanout:
	rm -f *.o

%Main: %Main.o $(OBJECTS)
	$(CXX) -o $@ $^ $(LIBRARIES)

%.o: %.cpp $(HEADERS)
	$(CXX) -c $<
