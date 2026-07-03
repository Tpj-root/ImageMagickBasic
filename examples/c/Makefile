CC      = gcc
CXX     = g++

CFLAGS  = -Wall -O2
CXXFLAGS= -Wall -O2

TARGET  = demo

OBJS = image.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)


image.o: image.c
	$(CC) $(CFLAGS) -c image.c

clean:
	rm -f *.o $(TARGET)
