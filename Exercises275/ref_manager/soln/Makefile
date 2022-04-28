
we3_solution: ref_manager.o we3_test.o
	g++ -o we3_solution ref_manager.o we3_test.o

ref_manager.o: ref_manager.cpp ref_manager.h
	g++ -c ref_manager.cpp

we3_test.o: we3_test.cpp ref_manager.h
	g++ -c we3_test.cpp

clean:
	rm *.o we3_solution
