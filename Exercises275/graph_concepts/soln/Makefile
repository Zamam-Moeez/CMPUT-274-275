
we6_solution: digraph.o graph_concepts.o
	g++ -o we6_solution digraph.o graph_concepts.o

digraph.o: digraph.cpp digraph.h
	g++ -c digraph.cpp

graph_concepts.o: graph_concepts.cpp digraph.cpp digraph.h
	g++ -c graph_concepts.cpp

run: we6_solution edmonton-roads-2.0.1.txt
	./we6_solution < edmonton-roads-2.0.1.txt

clean:
	rm *.o we6_solution
