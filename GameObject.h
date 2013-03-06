#ifdef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject{
	private:

		SDL_Rect objectBox;

		int xmove,ymove;

		int direction,frame;

	public:

		GameObject();

		GameObject(int x, int y, int width, int height);

		bool collisionCheck(std::vector<SDL_Rect> &B);

		void move();

		void display();		
};

#endif