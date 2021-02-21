#include "Engine.hpp"
#include "HUD.hpp"
#include <SDL2/SDL_ttf.h>
#include <random>

HUD::HUD(){
	stick = TTF_OpenFont("./assets/stick.ttf", 48);
	if(stick == NULL){
		SDL_Log("No font. %s", TTF_GetError());
	}
	color.r=0;
	color.g=0;
	color.b=0;
	surface = TTF_RenderText_Solid(stick, "CRAZY BOUNCING BANANA, EPIC!", color); 
	if(surface == NULL){
		SDL_Log("Can't create text. %s", SDL_GetError());
	}
	texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), surface);
	if(texture == NULL){
		SDL_Log("Can't create texture. %s", SDL_GetError());
	}
	rect->x = 0;
	rect->y = 0;
	rect->w = surface->w;
	rect->h = surface->h;
	rng=std::mt19937(rd());
	uni=std::uniform_int_distribution<int>(0,255);
}

HUD::~HUD(){
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}

void HUD::update(double delta){
	elapsed += delta;
	if(elapsed > 1){
		color.r = uni(rng);
		color.b = uni(rng);
		color.g = uni(rng);
		surface = TTF_RenderText_Solid(stick, "CRAZY BOUNCING BANANA, EPIC!", color); 
		texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), surface);

	}
}

void HUD::draw(){
	SDL_Rect* dst = new SDL_Rect();
	dst->x = position.getX();
	dst->y = position.getY();
	dst->w = rect->w;
	dst->h = rect->h;
	SDL_RenderCopy(Engine::getRenderer(), texture, NULL, dst);
}
