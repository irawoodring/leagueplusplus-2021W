#include "Engine.hpp"
#include "Banana.hpp"
#include <SDL2/SDL.h>

int main(int argc, char** argv){
	SDL_Log("Starting up, with following arguments:");
	for(int i=0; i<argc; ++i){
		SDL_Log("%d = %s", i, argv[i]);
	}

	// Create a scene
	Scene one;
	// Create an engine.  Must happen early, creates the renderer.
	Engine engine(1024, 768);

	// Make a banana and add to scene. Should update and draw.
	Banana* b = new Banana();
	one.addUpdateable(b);
	one.addDrawable(b);

	// Set the scene in the engine
	engine.setScene(&one);
	
	// Get the engine running.
	engine.run();
}
