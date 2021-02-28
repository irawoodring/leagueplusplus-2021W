#include "Collision.hpp"
#include "Engine.hpp"
#include "HUD.hpp"
#include <SDL2/SDL.h>
#include <box2d/box2d.h>
#include "Banana.hpp"

int main(int argc, char** argv){
	SDL_Log("Starting up, with following arguments:");
	for(int i=0; i<argc; ++i){
		SDL_Log("%d = %s", i, argv[i]);
	}

	// Create a scene
	Scene one;
	// Create an engine.  Must happen early, creates the renderer.
	Engine engine(1024, 768);
	// Create the physics engine
	Collision c(b2Vec2(0.0, 0.0));
	// Make a banana and add to scene. Should update and draw.
	Banana* b = new Banana("./assets/banana.png");
	// Add banana to physics
	b2Body* body = c.addObject(b);
	b->setBody(body);
	one.addUpdateable(b);
	one.addDrawable(b);
	one.addUpdateable(&c);
	auto b_up = [b](double delta) { b->up(delta); };
	auto b_down = [b](double delta) { b->down(delta); };
	auto b_left = [b](double delta) { b->left(delta); };
	auto b_right = [b](double delta) { b->right(delta); };
	one.addKeyEvent( SDLK_w, b_up );
	one.addKeyEvent( SDLK_a, b_left );
	one.addKeyEvent( SDLK_d, b_right );
	one.addKeyEvent( SDLK_s, b_down );

	// Add the HUD
	HUD* h = new HUD();
	one.addUpdateable(h);
	one.addDrawable(h);

	// Set the scene in the engine
	engine.setScene(&one);
	
	// Get the engine running.
	engine.run();
}
