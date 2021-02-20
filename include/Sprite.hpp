#ifndef			__HPP__SPRITE__
#define			__HPP__SPRITE__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Interfaces.hpp"

class Sprite : public DUGameObject {
	public:
		Sprite(std::string path);
		Sprite(SDL_Surface* surface);
        ~Sprite();
		void update(double delta);
		void draw();	
	private:
		void CreateTexture(SDL_Surface* surface);
};

#endif
