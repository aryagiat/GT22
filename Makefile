FLAGS = -pedantic-errors -std=c++11

keylog.o: keylog.cpp keylog.h
	g++ $(FLAGS) -c $<

start.o: ./home/start.cpp keylog.h
	g++ $(FLAGS) -c $<

start: keylog.o start.o
	g++ $(FLAGS) $^ -o $@

main.o: main.cpp keylog.h ./home/start.h
	g++ $(FLAGS) -c $<

main: keylog.o start.o main.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f start main *.o

.PHONY: clean


nothing: ./console/console.o  ./console/console.cpp