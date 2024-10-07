CC=gcc
INCLUDES=-I.
CFLAGS=-c -Wall -g $(INCLUDES)
LDFLAGS=-lm
HW2_SOURCES=hw3.c heap.c util.c
HW2_OBJECTS=$(HW2_SOURCES:.c=.o)
HW2_EXECUTABLE=hw3

all: $(SOURCES) $(HW2_EXECUTABLE)
 
$(HW2_EXECUTABLE): $(HW2_OBJECTS) 
	$(CC) $(HW2_OBJECTS) -o $@ $(LDFLAGS)

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o $(HW2_EXECUTABLE) 
