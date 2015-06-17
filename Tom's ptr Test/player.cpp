
#include "player.h"
#include "shot.h"

cPlayer::cPlayer(){

	pic_ = Texture("res/player.png");

	pos_ = Vec2f(0, 0);
	size_ = Vec2f(50, 50);
	cut_pos_ = Vec2f(0, 0);
	cut_size_ = Vec2f(64, 64);
	speed_ = Vec2f(1.0f, 1.0f);
	direction_ = UP;
	angle_ = 0;

}
cPlayer::~cPlayer(){}


Vec2f cPlayer::getPos(){
	return pos_;
}
Vec2f cPlayer::getSize(){
	return size_;
}

int cPlayer::getDirection(){
	return direction_;
}

bool cPlayer::isPushSpace(AppEnv& env){
	return env.isPushKey(GLFW_KEY_SPACE);
}


void cPlayer::update(AppEnv& env){

	if (env.isPressKey('D')){
		pos_.x() += speed_.x();
		direction_ = RIGHT;
		angle_ = (PI / 2) * 3;
	}
	if (env.isPressKey('A')){
		pos_.x() -= speed_.x();
		direction_ = LEFT;
		angle_ = (PI / 2);
	}
	if (env.isPressKey('W')){
		pos_.y() += speed_.y();
		direction_ = UP;
		angle_ = (PI * 2);
	}
	if (env.isPressKey('S')){
		pos_.y() -= speed_.y();
		direction_ = DOWN;
		angle_ = PI;
	}

}

void cPlayer::draw(){

	//ƒLƒƒƒ‰‚Ì‰¼’u‚«
	drawTextureBox(pos_.x(), pos_.y(), size_.x(), size_.y(),
		cut_pos_.x(), cut_pos_.y(), cut_size_.x(), cut_size_.y(),
		pic_, Color(1, 1, 1),
		angle_, Vec2f(1, 1), Vec2f(size_ / 2));

}