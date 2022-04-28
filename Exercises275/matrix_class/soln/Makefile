
we5_solution: matrix.o we5_test.o
	g++ -o we5_solution matrix.o we5_test.o

matrix.o: matrix.cpp matrix.h
	g++ -c matrix.cpp

we5_test.o: we5_test.cpp matrix.h
	g++ -c we5_test.cpp

clean:
	rm *.o we5_solution
