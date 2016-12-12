#pragma once
#include "Sprite.h"
#include "Computer.h"

class PongBall :
	public Sprite
{
public:
	PongBall(sf::Vector2f , std::string );
	PongBall();
	void move();
	void reset(float );
	void collision(Sprite &, Computer &);

private:
	void wallCollision();
	void findBounceAngle(float , float );

	float ballX;
	float ballY;
	float bounceAngle;
	float const PADDLEHEIGHT = 100.0f;
	float const MAXBOUNCEANGLE = 1.22173f;
	float const MOVESPEED = 9.0f;
};