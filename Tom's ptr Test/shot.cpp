
#include "shot.h"
#include "player.h"

cShot::cShot() :
shot_pic("res/shot.png")
{

	pos = Vec2f(100, 100);
	size = Vec2f(5, 20);
	cut_pos = Vec2f(0, 0);
	cut_size = Vec2f(32, 32);
	speed = Vec2f(0, 10.0f);
	direction = UP;

	is_show = false;

}
cShot::~cShot(){}


bool cShot::isShowShot(){
	return is_show;
}
void cShot::setIsShow(){
	if (!is_show)
		is_show = true;
}


Vec2f cShot::setPos(Vec2f get_pos){
	if (!is_show)
		pos = get_pos;
	return get_pos;
}

void cShot::setDirection(int get_direction){

	if (!is_show){
		if (get_direction == LEFT){
			direction = LEFT;
			speed = Vec2f(-10.0f, 0);
			angle = (PI / 2) * 3;
		}
		if (get_direction == RIGHT){
			direction = RIGHT;
			speed = Vec2f(10.0f, 0);
			angle = (PI / 2);
		}
		if (get_direction == DOWN){
			direction = DOWN;
			speed = Vec2f(0, -10.0f);
			angle = (PI * 2);
		}
		if (get_direction == UP){
			direction = UP;
			speed = Vec2f(0, 10.0f);
			angle = PI;
		}
	}

}


void cShot::updata(){

	if (is_show){
		pos += speed;

		if (pos.x() < -WIDTH / 2 || pos.x() > WIDTH / 2 ||
			pos.y() < -HEIGHT / 2 || pos.y() > HEIGHT / 2){
			is_show = false;
		}

	}
}

void cShot::draw(){

	//ƒLƒƒƒ‰‚Ì‰¼’u‚«
	drawTextureBox(pos.x(), pos.y(), size.x(), size.y(),
		cut_pos.x(), cut_pos.y(), cut_size.x(), cut_size.y(),
		shot_pic, Color(1, 1, 1),
		angle, Vec2f(1, 1), Vec2f(size / 2));

}