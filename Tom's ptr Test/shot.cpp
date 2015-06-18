
#include "shot.h"
#include "player.h"

cPlayer player;

cShot::cShot(){

	pos_ = Vec2f(0, 0);
	size_ = Vec2f(5, 20);
	cut_pos_ = Vec2f(0, 0);
	cut_size_ = Vec2f(32, 32);
	speed_ = Vec2f(0, 0);
	direction_ = UP;

	shot_init = {
		pos_, size_,
		cut_pos_, cut_size_,
		speed_, 
		0,
		direction_, 
		false
	};

}
cShot::~cShot(){}


void cShot::create(bool is_show, Vec2f player_pos, int player_direction){

	pic_ = Texture("res/shot.png");

	pShot obj = pShot(new cShot);

	shot.push_back(shot_init);

	for (auto& shots : shot){

		if (!shots.is_show){
			if (player_direction == LEFT){
				shots.direction = LEFT;
				shots.speed = Vec2f(-10.0f, 0);
				shots.angle = (PI / 2) * 3;
			}
			if (player_direction == RIGHT){
				shots.direction = RIGHT;
				shots.speed = Vec2f(10.0f, 0);
				shots.angle = (PI / 2);
			}
			if (player_direction == DOWN){
				shots.direction = DOWN;
				shots.speed = Vec2f(0, -10.0f);
				shots.angle = (PI * 2);
			}
			if (player_direction == UP){
				shots.direction = UP;
				shots.speed = Vec2f(0, 10.0f);
				shots.angle = PI;
			}
		}

		if (!shots.is_show){
			shots.is_show = true;
			shots.pos = player_pos;
		}
	}

}


void cShot::update(){

	for (auto& shots : shot){

		if (shots.is_show){
			shots.pos += shots.speed;

			if (shots.pos.x() < -WIDTH / 2 || shots.pos.x() > WIDTH / 2 ||
				shots.pos.y() < -HEIGHT / 2 || shots.pos.y() > HEIGHT / 2){
				shots.is_show = false;
				shot.erase(shot.begin());
			}
		}

	}

}

void cShot::draw(){

	for (auto& shots : shot){

		if (shots.is_show){
			drawTextureBox(shots.pos.x(), shots.pos.y(), shots.size.x(), shots.size.y(),
				shots.cut_pos.x(), shots.cut_pos.y(), shots.cut_size.x(), shots.cut_size.y(),
				pic_, Color(1, 1, 1),
				shots.angle, Vec2f(1, 1), Vec2f(shots.size / 2));
		}

	}

}