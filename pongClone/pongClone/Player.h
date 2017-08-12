
#include "Sprite.h"

/*
	Derived from Sprite class.
*/
class Player :
	public Sprite
{
public:
	Player(sf::Vector2f, std::string);
	Player();
	void move(float);
	~Player();
};
