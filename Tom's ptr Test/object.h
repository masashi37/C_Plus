
#pragma once

#include "common.h"


class cObject{

protected:

	Texture pic_;

	Vec2f pos_;
	Vec2f size_;
	Vec2f cut_pos_;
	Vec2f cut_size_;
	Vec2f speed_;

	int direction_;

	float angle_;

	enum Direction{
		LEFT, RIGHT, DOWN, UP,
	};

public:

	cObject();
	virtual ~cObject();

	void update();
	void draw();

};