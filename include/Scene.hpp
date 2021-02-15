#ifndef			__HPP__SCENE__
#define			__HPP__SCENE__

#include <SDL2/SDL.h>
#include <vector>
#include <utility>
#include <functional>
#include "Interfaces.hpp"
#include "Utility.hpp"

class Scene {
	public:
		Scene();
		~Scene();
		void addUpdateable(Updateable* obj);
		void addDrawable(Drawable* obj);
		void addKeyEvent(SDL_Keycode key, Callback fn);

	private:
		std::vector<Updateable*> updateables;
		std::vector<Drawable*> drawables;
		std::vector<std::pair<SDL_Keycode, Callback > > keyEvents;

	friend class Engine;
};

#endif
