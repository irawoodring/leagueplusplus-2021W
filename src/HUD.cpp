#include "Engine.hpp"
#include "HUD.hpp"
#include "Sprite.hpp"
#include <SDL2/SDL_ttf.h>
#include <random>

HUD::HUD() : Sprite::Sprite("CRAZY BOUNCING BANANA, EPIC", "./assets/stick.ttf", 0, 48, 0, 0, 0){
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
		setColor(color);
	}
}
