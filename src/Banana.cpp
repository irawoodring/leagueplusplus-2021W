#include "Engine.hpp"
#include "Banana.hpp"

Banana::Banana(){
	surface = IMG_Load("./assets/banana.png");
	if( surface == NULL ){
		SDL_Log("Unable to load banana.");
		exit(1);
	}
	texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), surface);
	if( texture == NULL ){
		SDL_Log("-----> HAVE YOU CREATED THE ENGINE YET? <-----");
		SDL_Log("Unable to create texture. %s", SDL_GetError());
	}
	rect->x = 0;
	rect->y = 0;
	rect->w = surface->w;
	rect->h = surface->h;
}

Banana::~Banana(){
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}

void Banana::update(double delta){

}

void Banana::draw(){
	SDL_Rect* dst = new SDL_Rect();
	dst->x = position.getX();
	dst->y = position.getY();
	dst->w = rect->w;
	dst->h = rect->h;
	SDL_RenderCopy(Engine::getRenderer(), texture, NULL, dst);
}