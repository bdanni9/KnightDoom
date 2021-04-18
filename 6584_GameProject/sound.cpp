#include "sound.h"

#include <iostream>

sound::sound(std::string id, std::string path) : asset(id)
{
	_data = Mix_LoadWAV(path.c_str());

	if (_data == nullptr)
	{
		std::cout << "Failed to load WAV. Path: " << path << std::endl;
		std::cout << "Mixer Error: " << Mix_GetError();
		exit(1);
	}
}

Mix_Chunk* sound::data()
{
	return _data;
}
