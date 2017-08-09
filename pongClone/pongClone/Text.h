#pragma once
#include <SFML\Graphics.hpp>
class Text
{
public:
	Text(sf::Vector2f , float , std::string  , std::string );
	Text();
	void update();
	int getScore();
	void setText(std::string);
	void Render(sf::RenderWindow &);
	void reset();
	~Text();
private:
	sf::Font font;
	sf::Text text;
	int SCORE = 1;
};