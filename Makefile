FLAGS = -pedantic-errors -std=c++11

garage.o: ./home/garage.cpp ./home/garage.h
	g++ $(FLAGS) -c $<

console.o: ./console/console.cpp ./console/console.h
	g++ $(FLAGS) -c $<

keylog.o: keylog.cpp keylog.h
	g++ $(FLAGS) -c $<

start.o: ./home/start.cpp keylog.h ./home/garage.h ./console/console.h
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
