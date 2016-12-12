#include "Sprite.h"
Sprite::Sprite(sf::Vector2f position, std::string texturePath)
{
	initial_position = position;
	spriteTexture.loadFromFile(texturePath);
	spriteImage.setTexture(spriteTexture);
	spriteImage.setPosition(position);
}

Sprite::Sprite() {}

void Sprite::Render(sf::RenderWindow &window)
{
	window.draw(spriteImage);
}

void Sprite::move(float moveSpeed)
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

sf::Vector2f Sprite::spriteLocation()
{
	return spriteImage.getPosition();
}

void Sprite::reset()
{
	spriteImage.setPosition(initial_position);
}
