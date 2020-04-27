FLAGS = -pedantic-errors -std=c++11

keylog.o: ../keylog.cpp ../keylog.h
	g++ $(FLAGS) -c $<

console.o: console.cpp ../keylog.h console.h
	g++ $(FLAGS) -c $<

console: keylog.o console.o
	g++ $(FLAGS) $^ -o $@ -pthread

clean:
	rm -f console *.o

.PHONY: clean
