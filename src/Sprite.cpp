#include "Engine.hpp"
#include "Sprite.hpp"
#include <SDL2/SDL_ttf.h>

Sprite::Sprite(std::string path, int layer, int width, int height){
	surface = IMG_Load(path.c_str());
	this->layer = layer;
	this->width = width;
	this->height = height;
	if( surface == NULL ){
		SDL_Log("Unable to load sprite.");
		exit(1);
	}
        // initialize some of our pointers to null, just to be safe
        font = nullptr;
        texture = nullptr;
	createTexture(surface);
}

Sprite::Sprite(SDL_Surface* surface, int layer, int width, int height){
	this->layer = layer;
	this->width = width;
	this->height = height;
	createTexture(surface);
}

Sprite::Sprite(std::string text, std::string font, int layer, int fontSize, int r, int g, int b, int a){
	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;

	this->layer = layer;
	this->text = text;
	
	loadFont(font, fontSize);
	createTextSurface();
}

void Sprite::loadFont(std::string font, int fontSize){
        // close our old font before creating a new one, so that it's not abandoned in memory
        if(this->font != nullptr)
          TTF_CloseFont(this->font);
	this->font = TTF_OpenFont(font.c_str(), fontSize);
	if(this->font == NULL){
		SDL_Log("No font. %s", TTF_GetError());
	}
}

void Sprite::createTextSurface(){
        // free our old surface before creating a new one, so that it's not abandoned in memory
        if(surface != nullptr)
          SDL_FreeSurface(surface);
	surface = TTF_RenderText_Solid(this->font, this->text.c_str(), this->color);
	if(surface == NULL){
		SDL_Log("Can't create text. %s", SDL_GetError());
	}

	createTexture(surface);
}

void Sprite::createTexture(SDL_Surface* surface){
        // destroy our old texture before creating a new one, so that it's not abandoned in memory
        if(texture != nullptr)
          SDL_DestroyTexture(texture);
	texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), surface);
	if( texture == NULL ){
		SDL_Log("-----> HAVE YOU CREATED THE ENGINE YET? <-----");
		SDL_Log("Unable to create texture. %s", SDL_GetError());
	}

	rect->x = 0;
	rect->y = 0;
	
	if(width == -1){
		rect->w = surface->w;
	}else{
		rect->w = width;
	}

	if(height == -1){
		rect->h = surface->h;
	}else{
		rect->h = height;
	}
}

Sprite::~Sprite(){
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
  // remove rect from memory
  delete rect;
	if(font != NULL){
		TTF_CloseFont(font);
	}
}

void Sprite::update(double delta){
	// So we stop getting the compiler warning for now.
	delta = delta * 1;
}

void Sprite::draw(){
        // we want to put our rect on the stack here, so we don't have to explictly
        // remove it from the heap everytime we call draw
	SDL_Rect dst;
	dst.x = position.getX();
	dst.y = position.getY();

	dst.w = rect->w;
	dst.h = rect->h;

        // we can pass the address of dst to sdl_rendercopy so that it knows where to find it
	SDL_RenderCopy(Engine::getRenderer(), texture, NULL, &dst);
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

void Sprite::setLayer(int layer){
	this->layer = layer;
}

void Sprite::setSize(int width, int height){
	this->width = width;
	this->height = height;
}

bool Sprite::operator<(Sprite sprite){
	if(this->layer < sprite.layer) {
		return true;
	}

	return false;
}
