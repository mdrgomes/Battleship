#
# This is an example Makefile.  
# Typing 'make' will create the executable file.
#

# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile: $()
#
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#
# for C++ define  CC = g++

CC = gcc
CFLAGS = -Wall -I$(INC)
DEBUG = -g 

TARGET = init

SRC = src
BIN = bin
INC = inc

INCLUDE = $(wildcard $(INC)/*.h)
SOURCE = $(wildcard $(SRC)/*.c)
OBJECT = $(patsubst %,$(BIN)/%, $(notdir $(SOURCE:.c=.o)))

$(BIN)/$(TARGET) : $(OBJECT)
	$(CC) $(DEBUG) $(CFLAGS) -o $@ $^

$(BIN)/%.o : $(SRC)/%.c
	$(CC) $(DEBUG) $(CFLAGS) -c $< -o $@

.PHONY : help run clean

run : $(BIN)/$(TARGET)
	./$(BIN)/$(TARGET)

clean :
	rm -f $(OBJECT) $(BIN)/$(TARGET)

help : 
	@echo "src: $(SOURCE)"
	@echo "obj: $(OBJECT)"
# typing 'make' will invoke the first target entry in the file 
# (in this case the default target entry)
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
#

