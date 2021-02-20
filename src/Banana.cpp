#include "Engine.hpp"
#include "Banana.hpp"

Banana::Banana() : Sprite("./assets/banana.png") {
}

void Banana::left(double delta){
	position.setX(position.getX() - 100 * delta );
}
void Banana::right(double delta){
	position.setX(position.getX() + 100 * delta );
}
void Banana::up(double delta){
	position.setY(position.getY() - 100 * delta );
	SDL_Log("Delta: %f.", delta);
}
void Banana::down(double delta){
	position.setY(position.getY() + 100 * delta );
}
