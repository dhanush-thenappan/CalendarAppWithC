# Compiler
CC = gcc
# Compiler flags
CFLAGS = -Wall -Wextra -std=c99
# Target file (executable)
TARGET = builds/Calendar
# Source files
SRCS = src/CalendarAppWithC.c src/DayOfDateCalculator.c
OBJS = $(SRCS: .c=.o) 
# Default rule
all: $(TARGET)
# Building target
$(TARGET) : $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# How to build .o files from .c files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f $(OBJS) $(TARGET)
