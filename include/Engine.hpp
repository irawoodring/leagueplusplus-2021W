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
		void setFrameRate(double _frameRate);
		void setScene(Scene* scene);
		static SDL_Renderer* getRenderer();
	private:
		unsigned long current;
		unsigned long last;
		static SDL_Renderer* renderer;
		int height;
		int width;
		SDL_Window* window = nullptr;
		double frameRate;
		Scene* currentScene;
		int cumulative;
		int framecount;
};

#endif
