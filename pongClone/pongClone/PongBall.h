#pragma once
#include "Sprite.h"
#include "Computer.h"
#include "Audio.h"

class PongBall :
	public Sprite
{
public:
	PongBall(sf::Vector2f , std::string , std::string,std::string);
	PongBall();
	void move();
	void reset(float );
	void collision(Sprite &, Computer &);

private:
	void wallCollision();
	void findBounceAngle(float , float );
	Audio *paddleSound;
	Audio *wallSound;
	float ballX;
	float ballY;
	float bounceAngle;
	float const PADDLEHEIGHT = 100.0f;
	float const MAXBOUNCEANGLE = 1.22173f;
	float const MOVESPEED = 9.0f;
};