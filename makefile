CC = g++ -std=c++11
SRC_FILES = main.cpp read_utils.cpp class_reader.cpp class_displayer.cpp primitive_types.cpp opcode.cpp frame.cpp
EXEC = main
LIB = -lm

$(EXEC) : $(SRC_FILES)
	$(CC) $(SRC_FILES) -o $(EXEC) $(LIB)
#-fsanitize=address -ggdb

.PHONY: clean
clean:
	rm main
