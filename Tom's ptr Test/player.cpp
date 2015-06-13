
#include "player.h"
#include "shot.h"

cPlayer::cPlayer() :
player_pic("res/player.png")
{

	pos = Vec2f(0, 0);
	size = Vec2f(50, 50);
	cut_pos = Vec2f(0, 0);
	cut_size = Vec2f(64, 64);
	speed = Vec2f(1.0f, 1.0f);
	direction = UP;
	angle = 0;

}
cPlayer::~cPlayer(){}


Vec2f cPlayer::getPos(){
	return pos;
}
Vec2f cPlayer::getSize(){
	return size;
}

int cPlayer::getDirection(){
	return direction;
}

bool cPlayer::isPushSpace(AppEnv& env){
	return env.isPushKey(GLFW_KEY_SPACE);
}


void cPlayer::updata(AppEnv& env){


	if (env.isPressKey('D')){
		pos.x() += speed.x();
		direction = RIGHT;
		angle = (PI / 2) * 3;
	}
	if (env.isPressKey('A')){
		pos.x() -= speed.x();
		direction = LEFT;
		angle = (PI / 2);
	}
	if (env.isPressKey('W')){
		pos.y() += speed.y();
		direction = UP;
		angle = (PI * 2);
	}
	if (env.isPressKey('S')){
		pos.y() -= speed.y();
		direction = DOWN;
		angle = PI;
	}

}

void cPlayer::draw(){

	//ƒLƒƒƒ‰‚Ì‰¼’u‚«
	drawTextureBox(pos.x(), pos.y(), size.x(), size.y(),
		cut_pos.x(), cut_pos.y(), cut_size.x(), cut_size.y(),
		player_pic, Color(1, 1, 1),
		angle, Vec2f(1, 1), Vec2f(size / 2));

}