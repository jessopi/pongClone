#include "Sprite.h"

/*
	Loads textures from file and sets position for them.
*/
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

/*
	Returns X & Y coordinates for current sprite position.
*/
sf::Vector2f Sprite::spriteLocation()
{
	return spriteImage.getPosition();
}

/*
	Resets current image position to the initial position.
*/
void Sprite::reset()
{
	spriteImage.setPosition(initial_position);
}
Sprite::~Sprite()
{}
