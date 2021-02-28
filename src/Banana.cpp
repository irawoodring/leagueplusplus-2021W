#include "Engine.hpp"
#include "Banana.hpp"
#include "Sprite.hpp"
#include <string>

Banana::Banana(std::string path) : Sprite(path){
	
}

Banana::~Banana(){
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}

void Banana::setBody(b2Body* body){
	this->body = body;
}

void Banana::update(double delta){
	b2Vec2 b(0.0, 0.0);
	if(position.getX() > 1024){
		b.x -= 10;
	}
	else if(position.getX() < 0){
		b.x += 10;
	}
	else if(position.getY() < 0){
		b.y +=10;
	}
	else if(position.getY() > 768){
		b.y -= 10;
	}
	body->ApplyLinearImpulseToCenter(b, true);
}

void Banana::draw(){
	SDL_Rect* dst = new SDL_Rect();
	dst->x = position.getX();
	dst->y = position.getY();
	dst->w = rect->w;
	dst->h = rect->h;
	SDL_RenderCopy(Engine::getRenderer(), texture, NULL, dst);
}

void Banana::left(double delta){
	b2Vec2 force(-1.0, 1.0);
	body->ApplyLinearImpulseToCenter(force, true);
}

void Banana::right(double delta){
	b2Vec2 force(1.0, 0.0);
	body->ApplyLinearImpulseToCenter(force, true);
	
}

void Banana::up(double delta){
	b2Vec2 force(0.0, -1.0);
	body->ApplyLinearImpulseToCenter(force, true);
}

void Banana::down(double delta){
	b2Vec2 force(0.0, 1.0);
	body->ApplyLinearImpulseToCenter(force, true);
}
