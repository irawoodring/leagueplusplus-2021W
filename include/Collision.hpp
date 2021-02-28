#ifndef			__HPP_COLLISION__
#define			__HPP_COLLISION__

/**
 * This is NOT a decent attempt at a collision detection engine.
 * It is NOT optimized in any way.  It is merely a demonstration
 * of how we could plug a collision engine into our engine.
 **/

#include "Engine.hpp"
#include "Interfaces.hpp"
#include "Sprite.hpp"
#include <SDL2/SDL.h>
#include <box2d/box2d.h>
#include <vector>

class Collision: public UGameObject {

	public:
		Collision(b2Vec2 gravity);
		~Collision();
		void update(double delta);
		b2Body* addObject(Sprite* object);

	private:
		b2World* world;		
		std::vector<std::pair<Sprite*, b2Body*> > objects;

	friend class Engine;	
};

#endif
