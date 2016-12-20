#pragma once
#include <SFML\Audio.hpp>
#include <string>
class Audio
{
public:
	Audio(std::string);
	void play();
private:
	sf::Sound sound;
	sf::SoundBuffer soundBuffer;
};

