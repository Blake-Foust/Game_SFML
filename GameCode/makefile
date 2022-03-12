CFLAGS = -O
CC = g++
SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network

SRC = Game.o main.o TextureHolder.o
GameTest: $(SRC)
	$(CC) $(CFLAGS) -o GameTest $(SRC) $(SFML)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

Game.o: Game.cpp
	$(CC) $(CFLAGS) -c Game.cpp

TextureHolder.o: TextureHolder.cpp
	$(CC) $(CFLAGS) -c TextureHolder.cpp

clean:
	rm -f core *.o
