CC = gcc -std=c99 -g
SRC_FILES = main.c read_utils.c j8_class_reader.c j8_class_displayer.c opcode.c
EXEC = main
LIB = -lm

$(EXEC) : $(SRC_FILES)
	$(CC) $(SRC_FILES) -o $(EXEC) $(LIB)
#-fsanitize=address -ggdb

.PHONY: clean
clean:
	rm main
