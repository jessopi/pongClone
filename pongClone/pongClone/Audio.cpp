#include "Audio.h"

/*
	loads .wav files from folder
*/
Audio::Audio(std::string path)
{
	soundBuffer.loadFromFile(path);
	sound.setBuffer(soundBuffer);
}
void Audio::play()
{
	sound.play();
}
Audio::~Audio()
{}