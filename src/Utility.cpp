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

double Vector2::getY(){
	return this->y;
}

double Vector3::getZ(){
	return this->z;
}
