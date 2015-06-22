
#include "shot.h"
#include "player.h"

cPlayer player;

cShot::cShot(Vec2f player_pos, int player_direction){

	pic_ = Texture("res/shot.png");

	pos_ = player_pos;
	size_ = Vec2f(5, 20);
	cut_pos_ = Vec2f(0, 0);
	cut_size_ = Vec2f(32, 32);

	if (player_direction == LEFT){
		direction_ = LEFT;
		speed_ = Vec2f(-10.0f, 0);
		angle_ = (PI / 2) * 3;
	}
	if (player_direction == RIGHT){
		direction_ = RIGHT;
		speed_ = Vec2f(10.0f, 0);
		angle_ = (PI / 2);
	}
	if (player_direction == DOWN){
		direction_ = DOWN;
		speed_ = Vec2f(0, -10.0f);
		angle_ = (PI * 2);
	}
	if (player_direction == UP){
		direction_ = UP;
		speed_ = Vec2f(0, 10.0f);
		angle_ = PI;
	}

}
cShot::~cShot(){}


Vec2f cShot::getPos(){
	return pos_;
}

void cShot::update(){

	pos_ += speed_;

}

void cShot::draw(){

	drawTextureBox(pos_.x(), pos_.y(), size_.x(), size_.y(),
		cut_pos_.x(), cut_pos_.y(), cut_size_.x(), cut_size_.y(),
		pic_, Color(1, 1, 1),
		angle_, Vec2f(1, 1), Vec2f(size_ / 2));

}