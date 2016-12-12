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
void Computer::paddleFollow(float BallY)
{
	if (BallY + 3.0f > spriteImage.getPosition().y + 100.0f)
	{
		//while (spriteImage.getPosition().y + 80.0f < BallY)
	//	{
		spriteImage.move(0.0f, 6.0f);
	//	}
	}
	 if (BallY + 3.0f < spriteImage.getPosition().y)
	{
	//	while (spriteImage.getPosition().y +20 > BallY)
	//	{
			spriteImage.move(0.0f, -6.0f);
	//	}
	}
}