#ifndef			__H__INTERFACES__
#define			__H__INTERFACES__

#include <SDL2/SDL.h>
#include "Utility.hpp"

class GameObject {
	public:

	private:
		Vector3 position;
	protected:

};

class Updateable {
	public:
		virtual void update(double delta) = 0;	
		virtual ~Updateable() = default;
};

class Drawable {
	public:
		virtual void draw() = 0;
		virtual ~Drawable() = default;

	private:

	protected:
		SDL_Rect* rect;
		SDL_Texture* texture;
};

class UGameObject : public GameObject, public Updateable {

};

class DGameObject : public GameObject, public Drawable {

};

class DUGameObject : public GameObject, public Drawable, public Updateable {

};

#endif
