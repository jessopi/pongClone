#pragma once
#include "Sprite.h"
/*
	Derived from Sprite class.
*/
class Computer :
	public Sprite
{
public:
	Computer(sf::Vector2f , std::string );
	Computer();
	void paddleFollow(float,float);
	~Computer();
private:
	const float paddleSpeed = 375.0f;
};