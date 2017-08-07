#pragma once
#include <SFML\Graphics.hpp>
#include "Sprite.h"
#include "Audio.h"
#include "Computer.h"
#include "PongBall.h"
#include "Text.h"

class Game
{
public:
	Game();
	void start();
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
	Sprite *background;				//Background
	Sprite *p1;				//Player
	Computer *p2;			//Computer
	Text *p1_Score;		
	Text *p2_Score;
	PongBall* ball;
	Text *displayText;
	int isPaused = 1;
	int firstRun = 1;
};

