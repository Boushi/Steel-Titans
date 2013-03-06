GameObject(){
	objectBox.x = 0;
	objectBox.y = 0;
	objectBox.w = 0;
	objectBox.h = 0;
	xmove = 0;
	ymove = 0;
	direction = 0;
	frame = 0;
}

GameObject(int x, int y, int w, int h){
	objectBox.x = x;
	objectBox.y = y;
	objectBox.w = w;
	objectBox.h = h;
	xmove = 0;
	ymove = 0;
	direction = 0;
	frame = 0;
}

bool collisionCheck(std::vector<SDL_Rect> &B){
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


void move(){
	if(!(((objectBox.x+xmove)<0)||((objectBox.x+objectBox.w+xmove)>windowXSize)||collisionCheck(map))){
		objectBox.x+=xmove;
	}
	if(!(((objectBox.y+ymove)<0)||((objectBox.y+objectBox.h+xmove)>windowYSize)||collisionCheck(map))){
		objectBox.y+=ymove;
	}
}

