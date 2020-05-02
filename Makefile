FLAGS = -pedantic-errors -std=c++11

linkedlist.o: linkedlist.cpp linkedlist.h
	g++ $(FLAGS) -c $<

garage.o: ./home/garage.cpp ./home/garage.h
	g++ $(FLAGS) -c $<

console.o: ./console/console.cpp ./console/console.h
	g++ $(FLAGS) -c $<

keylog.o: keylog.cpp keylog.h
	g++ $(FLAGS) -c $<

start.o: ./home/start.cpp keylog.h linkedlist.h ./home/garage.h ./console/console.h
	g++ $(FLAGS) -c $<

start: keylog.o linkedlist.o start.o
	g++ $(FLAGS) $^ -o $@ -pthread

main.o: main.cpp keylog.h ./home/start.h
	g++ $(FLAGS) -c $< -pthread

main: keylog.o start.o main.o
	g++ $(FLAGS) $^ -o $@ -pthread

clean:
	rm -f start main *.o

.PHONY: clean
