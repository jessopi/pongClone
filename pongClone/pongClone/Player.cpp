#include "Player.h"

/*
	Loads textures from file and sets position for them.
*/
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
	Moves paddle in direction up if movespeed is negative and
	down if it is positive.
*/
void Player::move(float moveSpeed)
{
	spriteImage.move(0.0f, moveSpeed);

	/*
		Checks if paddle moves past predetermined borders if so
		paddles are set at the edge of the borders.
	*/
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
