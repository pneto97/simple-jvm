CC = gcc -std=c99
SRC_FILES = main.c read_utils.c j8_class_reader.c j8_class_displayer.c
EXEC = main

$(EXEC) : $(SRC_FILES)
	$(CC) $(SRC_FILES) -o $(EXEC) 
#-fsanitize=address -ggdb

.PHONY: clean
clean:
	rm main
