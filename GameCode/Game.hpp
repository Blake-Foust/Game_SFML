#ifndef  GAME_H
#define GAME_H

//SFML Library
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>

//Libaries
#include <iostream>


#define logl(x) std::cout << x << std::endl;

class Game
{
private:
	sf::RenderWindow mWindow;
	sf::Texture mTexture;
	sf::Sprite mPlayer;
private:
	void processEvents();
	void update(sf::Time);
	void render();

public:
	//Constructor/Destructor
	Game();
	virtual ~Game();

	//Functions
	void run();
	void handlePlayerInput(sf::Keyboard::Key, bool);

	//Variables
	sf::Time TimePerFrame = sf::seconds(1.f/60.f);
	bool mMovingUp = false;
	bool mMovingDown = false;
	bool mMovingRight = false;
	bool mMovingLeft = false;
	float playerSpeed = 1.0;

};


#endif 
