#include "Engine.hpp"
#include "Sprite.hpp"
#include <SDL2/SDL_ttf.h>

Sprite::Sprite(std::string path){
	surface = IMG_Load(path.c_str());

	if( surface == NULL ){
		SDL_Log("Unable to load sprite.");
		exit(1);
	}

	createTexture(surface);
}

Sprite::Sprite(SDL_Surface* surface){
	createTexture(surface);
}

Sprite::Sprite(std::string text, std::string font, int fontSize, int r, int g, int b, int a){
	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;

	this->text = text;
	
	loadFont(font, fontSize);
	createTextSurface();
}

void Sprite::loadFont(std::string font, int fontSize){
	this->font = TTF_OpenFont(font.c_str(), fontSize);
	if(this->font == NULL){
		SDL_Log("No font. %s", TTF_GetError());
	}
}

void Sprite::createTextSurface(){
	surface = TTF_RenderText_Solid(this->font, this->text.c_str(), this->color);
	if(surface == NULL){
		SDL_Log("Can't create text. %s", SDL_GetError());
	}

	createTexture(surface);
}

void Sprite::createTexture(SDL_Surface* surface){
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

void Sprite::setColor(SDL_Color color){
	setColor(color.r, color.g, color.b, color.a);
}

void Sprite::setColor(int r, int g, int b, int a){
	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	createTextSurface();
}

void Sprite::setFont(std::string font, int fontSize){
	loadFont(font, fontSize);
} 

void Sprite::setText(std::string text){
	this->text = text;
	createTextSurface();
}