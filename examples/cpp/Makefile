CC      = gcc
CXX     = g++

CFLAGS  = -Wall -O2
CXXFLAGS= -Wall -O2

TARGET  = demo

OBJS = main.o image.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

main.o: main.cpp image.h
	$(CXX) $(CXXFLAGS) -c main.cpp

image.o: image.c image.h
	$(CC) $(CFLAGS) -c image.c

clean:
	rm -f *.o $(TARGET)
