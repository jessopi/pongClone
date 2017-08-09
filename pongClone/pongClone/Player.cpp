#include "Player.h"

Player::Player(sf::Vector2f position, std::string texturePath)
{
	initial_position = position;
	spriteTexture.loadFromFile(texturePath);
	spriteImage.setTexture(spriteTexture);
	spriteImage.setPosition(position);
}
Player::Player()
{}

/*
	Takes float for input for direction and speed of paddle
	and function checks if the paddle goes out of bounds and sets its 
	position.
*/
void Player::move(float moveSpeed)
{
	spriteImage.move(0.0f, moveSpeed);

	if (spriteImage.getPosition().y <  21.0f)
	{
		spriteImage.setPosition(initial_position.x, 21.0f);
	}
	else if (spriteImage.getPosition().y > 498.5f - 100.0f)
	{
		spriteImage.setPosition(initial_position.x, 498.5f - 100.0f);
	}
}
Player::~Player()
{}
