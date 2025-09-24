CXX = g++
CXXFLAGS = -Wall -Wextra -O0 -std=c++17 -I/usr/include/gtest -pthread -fprofile-arcs -ftest-coverage
LDFLAGS  = -lgtest_main -lgtest -pthread -fprofile-arcs -ftest-coverage

SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)

TARGET = test_velha

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) *.gcda *.gcno *.gcov
