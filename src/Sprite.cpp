#include "Engine.hpp"
#include "Sprite.hpp"

Sprite::Sprite(std::string path){
	surface = IMG_Load(path.c_str());

	if( surface == NULL ){
		SDL_Log("Unable to load sprite.");
		exit(1);
	}

	CreateTexture(surface);
}

Sprite::Sprite(SDL_Surface* surface){
	CreateTexture(surface);
}

void Sprite::CreateTexture(SDL_Surface* surface){
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

Sprite::~Sprite(){
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}

void Sprite::update(double delta){
	// So we stop getting the compiler warning for now.
	delta = delta * 1;
}

void Sprite::draw(){
	SDL_Rect* dst = new SDL_Rect();
	dst->x = position.getX();
	dst->y = position.getY();
	dst->w = rect->w;
	dst->h = rect->h;
	SDL_RenderCopy(Engine::getRenderer(), texture, NULL, dst);
}