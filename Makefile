FLAGS = -pedantic-errors -std=c++11

keylog.o: keylog.cpp keylog.h
	g++ $(FLAGS) -c $<

start.o: ./home/start.cpp keylog.h
	g++ $(FLAGS) -c $<

start: keylog.o start.o
	g++ $(FLAGS) $^ -o $@ -pthread

main.o: main.cpp keylog.h ./home/start.h
	g++ $(FLAGS) -c $< -pthread

main: keylog.o start.o main.o
	g++ $(FLAGS) $^ -o $@ -pthread

clean:
	rm -f start main *.o

.PHONY: clean
