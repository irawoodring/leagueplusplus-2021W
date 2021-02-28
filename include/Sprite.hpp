#ifndef			__HPP__SPRITE__
#define			__HPP__SPRITE__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Interfaces.hpp"
#include "Utility.hpp"

class Sprite : public DUGameObject {
	public:
		Sprite(std::string Image);
        	Sprite(SDL_Surface* inputSurface);
		~Sprite();
		void draw();	
	private:
		Vector3 velocity;
	
	friend class Collision;

};

#endif
