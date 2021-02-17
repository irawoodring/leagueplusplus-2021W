#ifndef			__HPP__BANANA__
#define			__HPP__BANANA__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Interfaces.hpp"

class Banana : public DUGameObject {
	public:
		Banana();
		~Banana();
		void update(double delta);
		void draw();	
};

#endif
