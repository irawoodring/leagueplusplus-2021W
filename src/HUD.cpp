#include "Engine.hpp"
#include "HUD.hpp"
#include <SDL2/SDL_ttf.h>

HUD::HUD(){
	TTF_Font* stick = TTF_OpenFont("./assets/stick.ttf", 24);
	if(stick == NULL){
		SDL_Log("No font. %s", TTF_GetError());
	}
	SDL_Color color={0,0,0,127};
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
}

HUD::~HUD(){
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}

void HUD::update(double delta){

}

void HUD::draw(){
	SDL_Rect* dst = new SDL_Rect();
	dst->x = position.getX();
	dst->y = position.getY();
	dst->w = rect->w;
	dst->h = rect->h;
	SDL_RenderCopy(Engine::getRenderer(), texture, NULL, dst);
}
