CC       = g++
CFLAGS   =
CPPFLAGS = --std=c++17 -Werror -Wall -Wextra 
LDFLAGS  =

TARGET = fibonacci

SRCS = main.cpp ArgParser.cpp Fibonacci.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ -o $@

clean:
	rm -f $(TARGET)
