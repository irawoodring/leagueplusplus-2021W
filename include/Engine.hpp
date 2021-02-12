#ifndef			__HPP__ENGINE__
#define			__HPP__ENGINE__

#include "Interfaces.hpp"
#include "Scene.hpp"
#include <SDL2/SDL.h>

class Engine {
	public:
		Engine(int _width, int _height);
		~Engine();
		void run();
		static SDL_Renderer* renderer;
		void setFrameRate(double _frameRate);
		void setScene(Scene* scene);
	private:
		int height;
		int width;
		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = renderer;
		double frameRate;
		Scene* currentScene;
};




#endif
