#include "Tank.h"
//#include "Bullet.h"

Tank::Tank(int x, int y){
	objectBox.x = x;
	objectBox.y = y;
	objectBox.w = 16;
	objectBox.h = 16;
	xmove = 0;
	ymove = 0;
	direction = 0;
	frame = 0;
	windowXSize = 640;
	windowYSize = 480;
    tank = NULL;

    clipsRight[0].x = 0;
    clipsRight[0].y = 16;
    clipsRight[0].w = 16;
    clipsRight[0].h = 16;

    clipsRight[1].x = 16;
    clipsRight[1].y = 16;
    clipsRight[1].w = 16;
    clipsRight[1].h = 16;

    clipsLeft[0].x = 0;
    clipsLeft[0].y = 48;
    clipsLeft[0].w = 16;
    clipsLeft[0].h = 16;

    clipsLeft[1].x = 16;
    clipsLeft[1].y = 48;
    clipsLeft[1].w = 16;
    clipsLeft[1].h = 16;

    clipsUp[0].x = 0;
    clipsUp[0].y = 0;
    clipsUp[0].w = 16;
    clipsUp[0].h = 16;

    clipsUp[1].x = 16;
    clipsUp[1].y = 0;
    clipsUp[1].w = 16;
    clipsUp[1].h = 16;

    clipsDown[0].x = 0;
    clipsDown[0].y = 32;
    clipsDown[0].w = 16;
    clipsDown[0].h = 16;

    clipsDown[1].x = 16;
    clipsDown[1].y = 32;
    clipsDown[1].w = 16;
    clipsDown[1].h = 16;
}

void Tank::controlTank(){
	if( event.type == SDL_KEYDOWN )
    {
        switch( event.key.keysym.sym )
        {
            case SDLK_RIGHT: xmove += 2; break;
            case SDLK_LEFT: xmove -= 2; break;
            case SDLK_UP: ymove -= 2; break;
            case SDLK_DOWN: ymove += 2; break;
            //case SDLK_SPACE: bullets.push_back(Bullet(objectBox,direction)); break;
        }
    }
    else if( event.type == SDL_KEYUP )
    {
        switch( event.key.keysym.sym )
        {
            case SDLK_RIGHT: xmove -= 2; break;
            case SDLK_LEFT: xmove += 2; break;
            case SDLK_UP: ymove += 2; break;
            case SDLK_DOWN: ymove -= 2; break;
        }
    }
}

void Tank::display(){
	if( xmove < 0 )
    {
        direction = 3;
        frame++;
    }
    else if( xmove > 0 )
    {
        direction = 1;
        frame++;
    }else if(ymove < 0){
        direction = 0;
        frame++;
    }else if(ymove > 0){
        direction = 2;
        frame++;
    }
    else
    {
        frame = 0;
    }

    if( frame >= 2 )
    {
        frame = 0;
    }

    if(direction == 1){
        applySurface(objectBox.x, objectBox.y, tank, tankSurface, &clipsRight[frame]);
    }else if(direction == 3){
        applySurface(objectBox.x, objectBox.y, tank, tankSurface, &clipsLeft[frame] );
    }else if(direction == 0){
        applySurface(objectBox.x,objectBox.y, tank, tankSurface, &clipsUp[frame]);
    }else if(direction == 2){
        applySurface(objectBox.x, objectBox.y, tank, tankSurface, &clipsDown[frame]);
    }
}
