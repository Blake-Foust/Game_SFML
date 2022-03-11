#ifndef  GAME_H
#define GAME_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Game
{
private:
	sf::RenderWindow mWindow;
	sf::CircleShape  mPlayer;	
private:
	void processEvents();
	void update();
	void render();

public:
	//Constructor/Destructor
	Game();
	virtual ~Game();

	//Functions
	void run();

};


#endif 
