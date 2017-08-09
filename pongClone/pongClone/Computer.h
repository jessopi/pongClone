#pragma once
#include "Sprite.h"
class Computer :
	public Sprite
{
public:
	Computer(sf::Vector2f , std::string );
	Computer();
	void paddleFollow(float,float);
	~Computer();
private:
	const float paddleSpeed = 400.0f;
};