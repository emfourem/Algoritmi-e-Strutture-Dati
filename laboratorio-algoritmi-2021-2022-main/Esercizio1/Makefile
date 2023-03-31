CC = gcc

all: create_directory bin/array

testq: create_directory bin/array_tests_quicksort 

testb: create_directory bin/array_tests_bisort 

CFLAGS = -Wall -Wextra -Wpedantic -Wconversion

INCLUDES = src/*.h

COMMON_DEPS = $(INCLUDES) Makefile

build/%.o: src/%.c $(COMMON_DEPS)
# questa istruzione %.o funziona da for per ogni file *.o che cerca nella src i file .c li compila fino a -c prima di effettuare il linking e li stora in build
	$(CC) $(CFLAGS) -c $< -o $@

bin/array: build/array.o build/sorting_library.o build/array_main.o $(COMMON_DEPS)
	$(CC) build/array.o build/sorting_library.o build/array_main.o -o bin/array

bin/array_tests_quicksort: build/array_tests_quicksort.o build/array.o build/sorting_library.o build/unity.o build/test.o $(COMMON_DEPS)
	$(CC) build/array_tests_quicksort.o build/array.o build/sorting_library.o build/test.o build/unity.o -o bin/array_tests_quicksort

bin/array_tests_bisort: build/array_tests_bisort.o build/array.o build/sorting_library.o build/unity.o build/test.o $(COMMON_DEPS)
	$(CC) build/array_tests_bisort.o build/array.o build/sorting_library.o build/test.o build/unity.o -o bin/array_tests_bisort

create_directory:
	mkdir -p bin build

run:
	bin/./array "/home/michele/Documenti/laboratorio-algoritmi-2021-2022-main/Esercizio1/records.csv" "records_output.csv" quicksort 2

runq: 
	bin/./array_tests_quicksort

runb:
	bin/./array_tests_bisort

clean:
	rm -f build/* bin/* records_output.csv
	rmdir bin build