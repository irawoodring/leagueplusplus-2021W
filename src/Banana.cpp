#include "Engine.hpp"
#include "Banana.hpp"

Banana::Banana() : Sprite("./assets/banana.png") {
}

// Simple update method to show that you can override the sprite update to add functionality
void Banana::update(double delta){
	// So we stop getting the compiler warning for now.
	position.setX(position.getX() + velocity.getX() * delta);
	position.setY(position.getY() + velocity.getY() * delta);
	if(position.getX() > 1024-rect->w || position.getX() < 0){
		velocity.setX(- velocity.getX());
	}
	if(position.getY() > 768-rect->h || position.getY() < 0){
		velocity.setY(- velocity.getY());
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
