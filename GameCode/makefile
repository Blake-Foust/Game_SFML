CFLAGS = -O
CC = g++
SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network

SRC = Game.o main.o
GameTest: main.o Game.o
	$(CC) $(CFLAGS) -o GameTest $(SRC) $(SFML)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

Game.o: Game.cpp
	$(CC) $(CFLAGS) -c Game.cpp

clean:
	rm -f core *.o
