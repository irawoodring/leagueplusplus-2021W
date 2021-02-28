#ifndef			__HPP__BANANA__
#define			__HPP__BANANA__

#include "Sprite.hpp"
#include "Interfaces.hpp"
#include "Utility.hpp"
#include <box2d/box2d.h>
#include <string>

class Banana : public Sprite {
	public:
		Banana(std::string path);
		~Banana();
		void update(double delta);
		void draw();	
		void left(double delta);
		void right(double delta);
		void up(double delta);
		void down(double delta);
		void setBody(b2Body* body);
	private:
		Vector3 velocity;
		b2Body* body;

};

#endif
