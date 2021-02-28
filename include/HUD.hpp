#ifndef			__HPP__HUD__
#define			__HPP__HUD__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Interfaces.hpp"
#include "Utility.hpp"
#include <random>

class HUD : public DUGameObject {
	public:
		HUD();
		~HUD();
		void update(double delta);
		void draw();	
	private:
		TTF_Font* stick;
		SDL_Color color;
		int elapsed;
		std::random_device rd;
		std::mt19937 rng;
		std::uniform_int_distribution<int> uni;

};

#endif
