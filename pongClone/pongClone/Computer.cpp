#include "Computer.h"

Computer::Computer(sf::Vector2f position, std::string texturePath)
{
	spriteTexture.loadFromFile(texturePath);
	spriteImage.setTexture(spriteTexture);
	spriteImage.setPosition(position);
}
Computer::Computer()
{
}
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