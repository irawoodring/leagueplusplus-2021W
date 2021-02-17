#include "Engine.hpp"
#include "Scene.hpp"

// For linking purposes, we need to declare this static member in the cpp file.
SDL_Renderer* Engine::renderer = nullptr;

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
	if( Engine::renderer == nullptr ){
		SDL_Log("Could not create a renderer. %s", SDL_GetError());
	}
}

Engine::~Engine(){
	SDL_Log("Destroying renderer.");
	SDL_DestroyRenderer(Engine::renderer);
	SDL_Log("Destroying window.");
	SDL_DestroyWindow(window);
	SDL_Log("Shutting down...");
	SDL_Quit();
	SDL_Log("Shutdown complete.");
}

void Engine::run(){
	if(currentScene == nullptr){
		SDL_Log("No scene added yet to engine! - Aborting.");
		return;
	}
	bool quit = false;
	SDL_Event event;
	last = SDL_GetTicks();
	while(!quit){
		last = current;
		current = SDL_GetTicks();
		int delta = current - last;
		double gameDelta = (double)delta * 0.001;
		// Get events
		while(SDL_PollEvent(&event) > 0){
			if(event.type == SDL_QUIT){
				quit = true;
			}

			// Iterate over keyboard events
			
		}

		// Update objects
		for(std::vector<Updateable*>::iterator it = currentScene->updateables.begin(); it != currentScene->updateables.end(); ++it){
			(*it)->update(gameDelta);
		}			
		
		SDL_SetRenderDrawColor(Engine::renderer, 0, 101, 164, 255);
		SDL_RenderClear(Engine::renderer);
		// Render
		for(std::vector<Drawable*>::iterator it = currentScene->drawables.begin(); it != currentScene->drawables.end(); ++it){
			(*it)->draw();
		}
		SDL_RenderPresent(Engine::renderer);
	}
}

void Engine::setFrameRate(double _frameRate){
	this->frameRate = _frameRate;
}

void Engine::setScene(Scene* scene){
	this->currentScene = scene;	
}

SDL_Renderer* Engine::getRenderer(){
	return Engine::renderer;
}
