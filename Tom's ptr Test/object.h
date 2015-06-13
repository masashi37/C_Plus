
#pragma once

#include "common.h"


class cObject{

protected:

	Vec2f pos;
	Vec2f size;
	Vec2f cut_pos;
	Vec2f cut_size;

	Vec2f speed;

	int direction;

	float angle;

	enum Direction{
		LEFT, RIGHT, DOWN, UP,
	};

public:

	cObject();
	virtual ~cObject();

	void updata();
	void draw();

};