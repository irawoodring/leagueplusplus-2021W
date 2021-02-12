#include "Engine.hpp"

Engine::Engine(int _width, int _height){
	this->width = _width;
	this->height = _height;
	frameRate = 1000.0 / 30;
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
	if( window == nullptr ){
		SDL_Log("Could not create a window. %s", SDL_GetError());
	}
	Engine::renderer = SDL_CreateRenderer(window, -1, 0);
	if( renderer == nullptr ){
		SDL_Log("Could not create a renderer. %s", SDL_GetError());
	}
	
}

Engine::~Engine(){
	SDL_DestroyRenderer(Engine::renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Engine::run(){
	bool quit = false;
	SDL_Event event;
	while(!quit){
		// Get events
		while(SDL_PollEvent(&event) > 0){
			if(event.type == SDL_QUIT){
				quit = true;
			}
			
		}

		// Update objects

		// Render
	}
}

void Engine::setFrameRate(double _frameRate){

}

void Engine::addScene(Scene* scene){
	this->scene = scene;	
}
