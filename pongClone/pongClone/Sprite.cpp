#include "Sprite.h"
#include <iostream>
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
}

sf::Vector2f Sprite::spriteLocation()
{
	return spriteImage.getPosition();
}

void Sprite::setSprite(float x, float y)
{
	spriteImage.setPosition(x, y);
}

void Sprite::reset()
{
	spriteImage.setPosition(initial_position);
}
