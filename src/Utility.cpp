#include "Utility.hpp"

Vector2::Vector2(double x, double y) {
	this->x = x;
	this->y = y;
}

Vector3::Vector3(double x, double y, double z) : Vector2(x, y) {
	this->z = z;
}

double Vector2::getX(){
	return this->x;
}

void Vector2::setX(double x){
	this->x = x;
}

double Vector2::getY(){
	return this->y;
}

void Vector2::setY(double y){
	this->y = y;
}

double Vector3::getZ(){
	return this->z;
}

void Vector3::setZ(double z){
	this->z = z;
}

