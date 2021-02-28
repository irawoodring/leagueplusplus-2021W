// From Ross Kuiper, Bret Miller, and Garett Gritters
// with a few modifications.
#include <string>
#include "Engine.hpp"
#include "Sprite.hpp"

Sprite::Sprite(std::string Image){
	surface = IMG_Load(Image.c_str());
	if( surface == NULL ){
		SDL_Log("Unable to load Sprite.");
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
	velocity.setX(0);
	velocity.setY(0);
	velocity.setZ(0);
}

Sprite::Sprite(SDL_Surface* inputSurface){
	surface = inputSurface;
	if( surface == NULL ){
		SDL_Log("Unable to load Sprite.");
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
	velocity.setX(0);
	velocity.setY(0);
	velocity.setZ(0);
}

Sprite::~Sprite(){
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}

void Sprite::draw(){
	SDL_Rect* dst = new SDL_Rect();
	dst->x = position.getX();
	dst->y = position.getY();
	dst->w = rect->w;
	dst->h = rect->h;
	SDL_RenderCopy(Engine::getRenderer(), texture, NULL, dst);
}
