
#pragma once

#include "common.h"


class Ball{

private:

	enum SpeedVector{
		RIGHT, DOWN, LEFT, UP
	};
	struct ballDate{
		Vec2f pos;
		float size;
		float speed;
		int speed_vector;
	};
	ballDate ball_;

	float space;
	int move_change_count;

public:

	Ball();

	void update();
	void draw();

};
