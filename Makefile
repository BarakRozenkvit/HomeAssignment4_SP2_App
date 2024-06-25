### @author:314638669, Barak10101998@gmail.com
#!make -f

CXX=c++
CXXFLAGS=-std=c++11 -Werror
VALGRIND_FLAGS==-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

INCLUDE = /opt/homebrew/include/QtWidgets /opt/homebrew/include/QtWidgets/QtWidgetsDepends
SOURCES= main.cpp TreeView.cpp
OBJECTS=$(subst .cpp,.o,$(SOURCES))

tree: main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o tree


test: TestCounter.o Test.o
	$(CXX) $(CXXFLAGS) $^ -o test

tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

valgrind: catan test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I $(INCLUDE) --compile $< -o $@

clean:
	rm -f *.o Catan test