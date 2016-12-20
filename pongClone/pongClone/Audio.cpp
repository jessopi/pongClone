#include "Audio.h"

Audio::Audio(std::string path)
{
	soundBuffer.loadFromFile(path);
	sound.setBuffer(soundBuffer);
}
void Audio::play()
{
	sound.play();
}