#ifndef			__H__INTERFACES__
#define			__H__INTERFACES__

#include <SDL2/SDL.h>
#include "Utility.hpp"

class GameObject {
	protected:
		Vector3 position;
};

class Updateable {
	public:
		virtual void update(double delta) = 0;	
		virtual ~Updateable() = default;
};

class Drawable {
	public:
		Drawable();
		virtual void draw() = 0;
		virtual ~Drawable() = default;

	protected:
		SDL_Rect* rect;
		SDL_Surface* surface;
		SDL_Texture* texture;
};

class UGameObject : public GameObject, public Updateable {

};

class DGameObject : public GameObject, public Drawable {

};

class DUGameObject : public GameObject, public Drawable, public Updateable {

};

#endif
