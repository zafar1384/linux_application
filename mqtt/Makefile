# Compiler and flags
CC      = gcc
CFLAGS  = -Wall -Wextra -g
LDFLAGS = -lpthread
INC     = -I ./

# Target executable
TARGET  = exe

# Source and header files
SRCS    = main.c mqtt.c
HEADERS = mqtt.h

# Object files
OBJS    = $(SRCS:.c=.o)

# Build target
all: $(TARGET)

# Rule for building the target executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

# Rule for compiling source files into object files
%.o: %.c $(HEADERS)
	$(CC) $(INC) $(CFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
