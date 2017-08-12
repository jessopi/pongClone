#include "Computer.h"

/*
	Loads textures from file and sets position for them.
*/
Computer::Computer(sf::Vector2f position, std::string texturePath)
{
	initial_position = position;
	spriteTexture.loadFromFile(texturePath);
	spriteImage.setTexture(spriteTexture);
	spriteImage.setPosition(position);
}
Computer::Computer()
{
}

/*
	Checks if the pongballs Y position is higher or lower than
	the paddles current Y position. If true then the paddle
	moves to the pongballs Y position.
*/
void Computer::paddleFollow(float BallY, float deltaTime)
{
	if (BallY + 4.0f  > spriteImage.getPosition().y + 100.0f)
	{	
			spriteImage.move(0.0f, paddleSpeed*deltaTime);
	}
	else if (BallY + 4.0f < spriteImage.getPosition().y)
	{
			spriteImage.move(0.0f, -paddleSpeed*deltaTime);	
	}
}
Computer::~Computer()
{}