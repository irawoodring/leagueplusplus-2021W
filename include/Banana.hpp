#ifndef			__HPP__BANANA__
#define			__HPP__BANANA__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Sprite.hpp"

class Banana : public Sprite {
	public:	
		Banana();
		void left(double delta);
		void right(double delta);
		void up(double delta);
		void down(double delta);

};

#endif
