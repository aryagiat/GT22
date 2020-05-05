FLAGS = -pedantic-errors -std=c++11

linkedlist.o: ./game_library/linkedlist.cpp ./game_library/linkedlist.h
	g++ $(FLAGS) -c $<

keylog.o: ./game_library/keylog.cpp ./game_library/keylog.h
	g++ $(FLAGS) -c $<

start.o: ./home/start.cpp ./game_library/keylog.h ./game_library/linkedlist.h ./home/garage.h ./console/console.h ./home/difficulty.h
	g++ $(FLAGS) -c $<

GT22: keylog.o linkedlist.o start.o
	g++ $(FLAGS) $^ -o $@ -pthread

clean:
	rm -f start start GT22 *.o

.PHONY: clean
