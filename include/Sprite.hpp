#ifndef			__HPP__SPRITE__
#define			__HPP__SPRITE__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Interfaces.hpp"

class Sprite : public DUGameObject {
	public:
		Sprite(std::string text, std::string font, int fontSize, int r = 255, int g = 255, int b = 255, int a = 255);
		Sprite(std::string path);
		Sprite(SDL_Surface* surface);
        ~Sprite();
		virtual void update(double delta);
		void draw();	
		void setText(std::string text);
		void setFont(std::string font, int fontSize);
		void setColor(int r, int g, int b, int a = 255);
		void setColor(SDL_Color color);
	private:
		std::string text;
		SDL_Color color;
		TTF_Font* font;
		void createTexture(SDL_Surface* surface);
		void loadFont(std::string font, int fontSize);
		void createTextSurface();
};

#endif
