#include "Engine.hpp"
#include "Banana.hpp"
#include <SDL2/SDL.h>

int main(int argc, char** argv){
	SDL_Log("Starting up, with following arguments:");
	for(int i=0; i<argc; ++i){
		SDL_Log("%d = %s", i, argv[i]);
	}

	Scene one;
	Engine engine(1024, 768);
	Banana* b = new Banana();
	one.addUpdateable(b);
	one.addDrawable(b);
	engine.setScene(&one);
	engine.run();
}
