#include "Game.hpp"


//Constructor
Game::Game():mWindow(sf::VideoMode(1200,800), "SFML Application"),
	     mPlayer()
{
	mPlayer.setRadius(40.f);
	mPlayer.setPosition(100.f,100.f);
	mPlayer.setFillColor(sf::Color::Cyan);
};

//Destructor
Game::~Game()
{
};

//Handles user input
void Game::processEvents()
{
	sf::Event event;
	while(mWindow.pollEvent(event))
	{
		switch(event.type)
		{
			case sf::Event::KeyPressed:
				handlePlayerInput(event.key.code, true);
				break;
			case sf::Event::KeyReleased:
				handlePlayerInput(event.key.code, false);
				break;
			case sf::Event::Closed:
				mWindow.close();
				break;
		}
	}
};

//Handles game logic
void Game::update(sf::Time deltaTime)
{
	sf::Vector2f movement(0.f,0.f);
	if(this->mMovingUp)
		movement.y -= this->playerSpeed;
	if(this->mMovingDown)
		movement.y += this->playerSpeed;
	if(this->mMovingLeft)
		movement.x -= this->playerSpeed;
	if(this->mMovingRight)
		movement.x += this->playerSpeed;
	
	mPlayer.move(movement);
};

//Renders game to screen
void Game::render()
{
	sf::Texture texture;
	if(!texture.loadFromFile("christmascard.png"))
	{
		mWindow.close();
	}
	sf::Sprite sprite(texture);
	sprite.setPosition(100.f,100.f);
	mWindow.clear();
	mWindow.draw(sprite);
	mWindow.display();
};

//Functions
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	mWindow.setVerticalSyncEnabled(true);
	while(mWindow.isOpen())
	{
		timeSinceLastUpdate += clock.restart();
		while(timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);

		}
		render();

	}
};

void Game::handlePlayerInput(sf::Keyboard::Key key, bool is_Pressed)
{
	switch (key)
	{
	case sf::Keyboard::W:
		this->mMovingUp = is_Pressed;
		break;
	case sf::Keyboard::D:
		this->mMovingRight = is_Pressed;
		break;
	case sf::Keyboard::A:
		this->mMovingLeft = is_Pressed;
		break;
	case sf::Keyboard::S:
		this->mMovingDown = is_Pressed;
		break;
	default:
		break;
	};
};