#pragma once
#include <string>
#include <SFML\Graphics.hpp>

class Sprite
{
public:
	Sprite(sf::Vector2f , std::string );
	Sprite();
	void Render(sf::RenderWindow &);
	sf::Vector2f spriteLocation();
	void reset();
protected:
	sf::Vector2f initial_position;
	sf::Texture spriteTexture;
	sf::Sprite spriteImage;
};