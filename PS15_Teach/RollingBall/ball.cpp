
#include "ball.h"
#include <iostream>


Ball::Ball(){

	ball_ = {
		Vec2f(-WIDTH / 2, HEIGHT / 2),
		30, 10, RIGHT
	};

	space = ball_.size * 2;
	move_change_count = 0;

}

void Ball::update(){

	//move
	switch (ball_.speed_vector){

	case RIGHT:
		ball_.pos.x() += ball_.speed;

		if (ball_.pos.x() > WIDTH / 2 - (space * move_change_count))
			ball_.speed_vector = DOWN;

		break;

	case DOWN:
		ball_.pos.y() -= ball_.speed;

		if (ball_.pos.y() < -HEIGHT / 2 + (space * move_change_count))
			ball_.speed_vector = LEFT;

		break;
	
	case LEFT:
		ball_.pos.x() -= ball_.speed;

		if (ball_.pos.x() < -WIDTH / 2 + (space * move_change_count)){
			ball_.speed_vector = UP;
			move_change_count++;
		}

		break;
	
	case UP:
		ball_.pos.y() += ball_.speed;

		if (ball_.pos.y() > HEIGHT / 2 - (space * move_change_count))
			ball_.speed_vector = RIGHT;

		break;

	}

}

void Ball::draw(){
	drawCircle(
		ball_.pos.x(), ball_.pos.y(),
		ball_.size, ball_.size,
		50, 3, Color::white);
}
