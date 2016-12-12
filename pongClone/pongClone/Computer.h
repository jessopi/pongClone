#pragma once
#include "Sprite.h"
class Computer :
	public Sprite
{
public:
	Computer(sf::Vector2f , std::string );
	Computer();
	void paddleFollow(float);
};