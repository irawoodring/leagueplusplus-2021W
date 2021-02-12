#ifndef			__HPP__SCENE__
#define			__HPP__SCENE__

#include "Engine.hpp"
#include "Interfaces.hpp"
#include <SDL2/SDL.h>
#include <vector>
#include <utility>
#include <functional>

class Scene {

	public:
		void addUpdateable(Updateable* obj);
		void addDrawable(Drawable* obj);
		void addEvent(SDL_Keycode key, Callback fn);

	private:
		std::vector<Updateable*> updateables;
		std::vector<Drawable*> drawables;
		std::vector<std::pair<SDL_Keycode, Callback > > keyEvents;

	friend class Engine;

};



#endif
