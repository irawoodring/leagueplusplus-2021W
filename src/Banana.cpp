#include "Engine.hpp"
#include "Banana.hpp"

Banana::Banana() : Sprite("./assets/banana.png") {
}

// Simple update method to show that you can override the sprite update to add functionality
void Banana::update(double delta){
	if(position.getX() > 600) {
		position.setX(0);
	}
}

void Banana::left(double delta){
	if(velocity.getX() > -200){
		velocity.setX(velocity.getX() - 10);
	}
}
void Banana::right(double delta){
	if(velocity.getX() < 200){
		velocity.setX(velocity.getX() + 10);
	}
}
void Banana::up(double delta){
	if(velocity.getY() > -200 ){
		velocity.setY(velocity.getY() - 10);
	}
}
void Banana::down(double delta){
	if(velocity.getY() < 200 ){
		velocity.setY(velocity.getY() + 10);
	}
}
