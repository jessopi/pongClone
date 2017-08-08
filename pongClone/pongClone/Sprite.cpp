#include "Sprite.h"
Sprite::Sprite(sf::Vector2f position, std::string texturePath)
{
	spriteTexture.loadFromFile(texturePath);
	spriteImage.setTexture(spriteTexture);
	spriteImage.setPosition(position);
}

Sprite::Sprite() {}

void Sprite::Render(sf::RenderWindow &window)
{
	window.draw(spriteImage);
}

sf::Vector2f Sprite::spriteLocation()
{
	return spriteImage.getPosition();
}

void Sprite::reset()
{
	spriteImage.setPosition(initial_position);
}
