CC = gcc -std=c99 -g
SRC_FILES = main.c read_utils.c class_reader.c class_displayer.c primitive_types.c opcode.c frame.c global.c instructions.c instruction_helpers.c
EXEC = main
LIB = -lm

$(EXEC) : $(SRC_FILES)
	$(CC) $(SRC_FILES) -o $(EXEC) $(LIB) 
#-fsanitize=address -ggdb

.PHONY: clean
clean:
	rm main
