#ifndef TANK_H
#define TANK_H

#include "GameObject.h"

class Tank: public GameObject{
	private:
		SDL_Surface *tank;

		SDL_Rect clipsRight[2];

		SDL_Rect clipsLeft[2];

		SDL_Rect clipsUp[2];
	
		SDL_Rect clipsDown[2];

	public:
		Tank(int x, int y);

		void controlTank();

		void display();
};

#endif
