CC = gcc
all: create_directory build/main_ex2
test: create_directory build/test

CFLAGS = -Wall -Wextra -Wpedantic -Wconversion

INCLUDES = src/*.h

COMMON_DEPS = $(INCLUDES) Makefile

bin/%.o: src/%.c $(COMMON_DEPS)
# questa istruzione %.o funziona da for per ogni file *.o che cerca nella src i file .c li compila fino a -c prima di effettuare il linking e li stora in build
	$(CC) $(CFLAGS) -c $< -o $@

build/main_ex2: bin/skiplist.o bin/main_ex2.o $(COMMON_DEPS)
	$(CC) bin/skiplist.o bin/main_ex2.o -o $@

build/test: bin/skiplist.o bin/unity.o bin/test_skiplist.o $(COMMON_DEPS)
	$(CC) bin/skiplist.o bin/unity.o bin/test_skiplist.o -o $@

create_directory:
	mkdir -p bin build

run:
	build/./main_ex2 '/home/michele/Documenti/laboratorio-algoritmi-2021-2022-main/Esercizio2/es2_dataset/dictionary.txt' '/home/michele/Documenti/laboratorio-algoritmi-2021-2022-main/Esercizio2/es2_dataset/correctme.txt'

runtest:
	build/./test
	
clean:
	rm -f build/* bin/* 
	rmdir bin build