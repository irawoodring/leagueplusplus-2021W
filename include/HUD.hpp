#ifndef			__HPP__HUD__
#define			__HPP__HUD__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Interfaces.hpp"
#include "Utility.hpp"

class HUD : public DUGameObject {
	public:
		HUD();
		~HUD();
		void update(double delta);
		void draw();	
	private:

};

#endif
