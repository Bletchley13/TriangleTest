LIB=-L/usr/include/
all: Triangle.c TestMainModule.c CUnitRunTest.c
	gcc $^ -o test $(LIB) -lcunit -lcurses -static
clean:
	rm -rf test

