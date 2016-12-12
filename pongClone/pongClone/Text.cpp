#include "Text.h"

Text::Text(sf::Vector2f position, float fontSize, std::string fontPath, std::string initialText)
{
	font.loadFromFile("./arial.ttf");
	text.setFont(font);
	text.setString(initialText);
	text.setCharacterSize(16);
	text.setStyle(sf::Text::Bold);
	text.setPosition(position);
}
Text::Text(){}

void Text::setText(std::string newString)
{
	text.setString(newString);
}
void Text::update()
{
	text.setString(std::to_string(SCORE++));
}

void Text::Render(sf::RenderWindow &window)
{
	window.draw(text);
}

void Text::reset()
{
	text.setString("0");
	SCORE = 1;
}
int Text::getScore() { return SCORE; }