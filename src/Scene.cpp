#include <SDL2/SDL.h>
#include "Interfaces.hpp"
#include "Utility.hpp"
#include "Scene.hpp"

Scene::Scene(){
	int i, count = SDL_GetNumAudioDevices(0);
	if(count < 1){
		SDL_Log("Audio error. %s", SDL_GetError());
	}
	for (i = 0; i < count; ++i) {
		SDL_Log("Audio device %d: %s", i, SDL_GetAudioDeviceName(i, 0));
	}
	SDL_AudioSpec wavSpec;
	unsigned int length;
	unsigned char* buffer;
	SDL_LoadWAV("./assets/song.wav", &wavSpec, &buffer, &length);
	SDL_AudioDeviceID device = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
	int success = SDL_QueueAudio(device, buffer, length);
	SDL_Log("Audio success: %d %s", success, SDL_GetError());
	SDL_PauseAudioDevice(device, 0);
}

Scene::~Scene(){

}

void Scene::addUpdateable(Updateable* obj){
	this->updateables.push_back(obj);
}

void Scene::addDrawable(Drawable* obj){
	this->drawables.push_back(obj);
}

void Scene::addKeyEvent(SDL_Keycode key, Callback fn){
	keyEvents.push_back(std::make_pair(key, fn));	
}
