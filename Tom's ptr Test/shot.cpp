
#include "shot.h"
#include "player.h"

cPlayer player;

cShot::cShot(){

	pic_ = Texture("res/shot.png");

	pos_ = Vec2f(100, 100);
	size_ = Vec2f(5, 20);
	cut_pos_ = Vec2f(0, 0);
	cut_size_ = Vec2f(32, 32);
	speed_ = Vec2f(0, 10.0f);
	direction_ = UP;

	is_show_ = false;

}
cShot::~cShot(){}


bool cShot::isShowShot(){
	return is_show_;
}
void cShot::setIsShow(){
	if (!is_show_)
		is_show_ = true;
}


Vec2f cShot::setPos(Vec2f get_pos){
	if (!is_show_)
		pos_ = get_pos;
	return get_pos;
}

void cShot::setDirection(int get_direction){

	if (!is_show_){
		if (get_direction == LEFT){
			direction_ = LEFT;
			speed_ = Vec2f(-10.0f, 0);
			angle_ = (PI / 2) * 3;
		}
		if (get_direction == RIGHT){
			direction_ = RIGHT;
			speed_ = Vec2f(10.0f, 0);
			angle_ = (PI / 2);
		}
		if (get_direction == DOWN){
			direction_ = DOWN;
			speed_ = Vec2f(0, -10.0f);
			angle_ = (PI * 2);
		}
		if (get_direction == UP){
			direction_ = UP;
			speed_ = Vec2f(0, 10.0f);
			angle_ = PI;
		}
	}

}


void cShot::update(){

	if (is_show_){
		pos_ += speed_;

		if (pos_.x() < -WIDTH / 2 || pos_.x() > WIDTH / 2 ||
			pos_.y() < -HEIGHT / 2 || pos_.y() > HEIGHT / 2){
			is_show_ = false;
		}

	}
}

void cShot::draw(){

	//ƒLƒƒƒ‰‚Ì‰¼’u‚«
	drawTextureBox(pos_.x(), pos_.y(), size_.x(), size_.y(),
		cut_pos_.x(), cut_pos_.y(), cut_size_.x(), cut_size_.y(),
		pic_, Color(1, 1, 1),
		angle_, Vec2f(1, 1), Vec2f(size_ / 2));

}