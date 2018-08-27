CXX = g++ -Wall -pedantic
MAIN_BINARIES = $(basename $(wildcard *Main.cpp))
HEADERS = $(wildcard *.hpp)
OBJECTS = $(addsuffix .o, $(basename $(wildcard *.cpp)))
LIBRARIES = -lsfml-graphics -lsfml-window -lsfml-system

.PRECIOUS: %.o
.PREFFIXES:
.PHONY: all compile test checkstyke

all: compile 

compile: $(MAIN_BINARIES)

style:
	cpplint --repository=. *.hpp *.cpp

clean:
	rm -f *.o
	rm -f $(MAIN_BINARIES)

cleanout:
	rm -f *.o

git:
	git add *
	echo Version:
	read v
	git commit -m "V0.01.$v"
	git push

%Main: $(OBJECTS)
	$(CXX) -o $@ $^ $(LIBRARIES)

%.o: %.cpp $(HEADERS)
	$(CXX) -c $< -o $@
