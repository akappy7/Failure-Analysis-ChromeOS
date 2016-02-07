CC=g++
CFLAGS=-c -Wall
LDFLAGS = -std=c++11
SOURCES=LED_signal.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=test
INCLUDE=
all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
.cpp.o:
	$(CC) $(LDFLAGS)  $(CFLAGS) $< -o $@
clean:
	$(RM) $(EXECUTABLE) *.o
