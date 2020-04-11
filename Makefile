FLAGS = -pedantic-errors -std=c++11

keylog.o: keylog.cpp keylog.h
	g++ $(FLAGS) -c $<

start.o: ./home/start.cpp keylog.h
	g++ $(FLAGS) -c $<

start: keylog.o start.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f start *.o

.PHONY: clean
