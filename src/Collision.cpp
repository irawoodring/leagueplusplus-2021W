#include "Collision.hpp"
#include "Interfaces.hpp"
#include "Sprite.hpp"
#include <SDL2/SDL.h>
#include <box2d/box2d.h>

const int METERSTOPIXELS = 30;

Collision::Collision(b2Vec2 gravity){
	SDL_Log("Creating world...");
	world = new b2World(gravity);
	SDL_Log("Created with requested gravity.");
}

Collision::~Collision(){
	delete world;
}

void Collision::update(double delta){
	world->Step(1.0 / 60.0, 1.0, 1.0);
	for(auto it = objects.begin(); it != objects.end(); ++it){
		b2Vec2 position = (*it).second->GetPosition();
		(*it).first->position.setX(position.x * 10);
		(*it).first->position.setY(position.y * 10);
	}
}

b2Body* Collision::addObject(Sprite* object){
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.angle = 45;
	bodyDef.position.Set(object->position.getX(), object->position.getY());

	b2Body* body = world->CreateBody(&bodyDef);
	
	b2PolygonShape box;
	box.SetAsBox(0.5, 0.5);

	b2FixtureDef fixture;
	fixture.shape = &box;
	fixture.density = .1;
	fixture.friction = 0.1;
	fixture.restitution = 0.5;
	body->CreateFixture(&fixture);
	objects.push_back(std::make_pair(object, body));
	return body;
}
