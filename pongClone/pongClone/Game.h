#pragma once
#include <SFML\Graphics.hpp>
#include "Sprite.h"
#include "Audio.h"
#include "Computer.h"
#include "PongBall.h"
#include "Text.h"
#include "Player.h"

class Game
{
public:
	Game();
	void start();
	~Game();
private:
	void checkScore();
	void render();
	void newGame();
	float deltaTime;

	const float ball_Radius = 8.0f;
	const float paddleSpeed = 400.0f;

	Audio *sound;
	sf::Event event;
	sf::Clock clock;
	sf::RenderWindow *window;

	Sprite *background;				
	Sprite *startScreen;
	Sprite *gameOver;
	Sprite *youWin;
	
	Player *p1;				
	Computer *p2;			
	Text *p1_Score;		
	Text *p2_Score;

	PongBall* ball;
	int isPaused = 1;
	int firstRun = 1;
};

