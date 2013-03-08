#include "GameObject.h"

GameObject::GameObject(){
	objectBox.x = 0;
	objectBox.y = 0;
	objectBox.w = 0;
	objectBox.h = 0;
	xmove = 0;
	ymove = 0;
	direction = 0;
	frame = 0;
	windowXSize = 640;
	windowYSize = 480;
}

GameObject::GameObject(int x, int y, int w, int h){
	objectBox.x = x;
	objectBox.y = y;
	objectBox.w = w;
	objectBox.h = h;
	xmove = 0;
	ymove = 0;
	direction = 0;
	frame = 0;
	windowXSize = 640;
	windowYSize = 480;
}

bool GameObject::collisionCheck(std::vector<SDL_Rect> &B){
    int maxXb, minXb, maxYb, minYb;

    for(int i = 0; i<B.size();i++){
        minXb = B[i].x;
        maxXb = B[i].x + B[i].w;
        minYb = B[i].y;
        maxYb = B[i].y + B[i].h;

        if(((objectBox.x+objectBox.w) > minXb)&&((objectBox.y+objectBox.h)>minYb)&&(objectBox.y<maxYb)&&(objectBox.x<maxXb)){
            return true;
        }

    }
    return false;
}

void GameObject::move(){
	if(!(((objectBox.x+xmove)<0)||((objectBox.x+objectBox.w+xmove)>windowXSize)||collisionCheck(map))){
		objectBox.x += xmove;
	}
	if(!(((objectBox.y+ymove)<0)||((objectBox.y+objectBox.h+xmove)>windowYSize)||collisionCheck(map))){
		objectBox.y += ymove;
	}
}

SDL_Surface* GameObject::loadImage(std::string file){
    SDL_Surface* loadedImage = NULL;
    SDL_Surface* optimizedImage = NULL;

    loadedImage = IMG_Load( file.c_str() );

    if( loadedImage != NULL )
    {
        optimizedImage = SDL_DisplayFormat( loadedImage );
        SDL_FreeSurface( loadedImage );

        if( optimizedImage != NULL )
        {
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 55, 0 ) );
        }
    }
    return optimizedImage;
}

void GameObject::applySurface(int x ,int y ,SDL_Surface* source ,SDL_Surface* destination ,SDL_Rect* clip){
    SDL_Rect offset;
	offset.x = x;
    offset.y = y;
    SDL_BlitSurface( source, clip, destination, &offset );
}