#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include <string>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

class GameObject{
	protected:

		static SDL_Surface *tankSurface;

		static SDL_Surface *aiSurface;

		static SDL_Surface *bulletSurface;

		std::vector<SDL_Rect> map;

		SDL_Rect objectBox;

		int xmove,ymove;

		int direction,frame;

		int windowXSize,windowYSize;

		SDL_Event event;

	public:

		GameObject();

		GameObject(int x, int y, int w, int h);

		bool collisionCheck(std::vector<SDL_Rect> &B);

		void move();

		SDL_Surface* loadImage(std::string file);

		void applySurface(int x ,int y ,SDL_Surface* source ,SDL_Surface* destination ,SDL_Rect* clip = NULL);

};

#endif
