LIB=-L/usr/include/
all: Triangle.c TestMainModule.c CUnitRunTest.c
	gcc $^ -fprofile-arcs -ftest-coverage -o test $(LIB) -lcunit -lcurses -static

test: Triangle.c TestMainModule.c CUnitRunTest.c
	gcc $^ -fprofile-arcs -ftest-coverage -o test $(LIB) -lcunit -lcurses -static


clean:
	rm -rf test && rm *.gcno 
