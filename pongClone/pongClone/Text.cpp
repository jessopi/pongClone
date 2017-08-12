#include "Text.h"

/*
	Loads font from file and sets character size, and position.
*/
Text::Text(sf::Vector2f position, float fontSize,std::string fontPath, std::string initialText)
{
	font.loadFromFile(fontPath);
	text.setFont(font);
	text.setString(initialText);
	text.setCharacterSize(15);
	text.setStyle(sf::Text::Bold);
	text.setPosition(position);
}
Text::Text(){}

void Text::setText(std::string newString)
{
	text.setString(newString);
}
/*
	Updates score when player or computer scores.
*/
void Text::update()
{
	text.setString(std::to_string(SCORE++));
}

void Text::Render(sf::RenderWindow &window)
{
	window.draw(text);
}

/*
	Resets score for new game
*/
void Text::reset()
{
	text.setString("0");
	SCORE = 1;
}
int Text::getScore() 
{ 
	return SCORE; 
}

Text::~Text()
{}