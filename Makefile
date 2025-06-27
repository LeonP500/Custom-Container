CXX = clang++
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror -pedantic

SRC = MyContainer.hpp Iterators.hpp
TEST = Tests.cpp
DEMO = Demo.cpp

all: Main

Main: $(DEMO:.cpp=.o)
	$(CXX) $(CXXFLAGS) -o Main $(DEMO:.cpp=.o)

Demo.o: $(DEMO) $(SRC)
	$(CXX) $(CXXFLAGS) -c $(DEMO)

test: TestRunner

TestRunner: $(TEST:.cpp=.o)
	$(CXX) $(CXXFLAGS) -o TestRunner $(TEST:.cpp=.o)

Tests.o: $(TEST) $(SRC)
	$(CXX) $(CXXFLAGS) -c $(TEST)

run-tests: test
	./TestRunner

valgrind: test
	valgrind --leak-check=full ./TestRunner

clean:
	rm -f *.o Main TestRunner
