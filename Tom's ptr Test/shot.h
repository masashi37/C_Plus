
#pragma once

#include "object.h"


typedef std::shared_ptr<class cShot>pShot;
class cShot :public cObject{

private:

	struct ShotDate{
		Vec2f pos;
		Vec2f size;
		Vec2f cut_pos;
		Vec2f cut_size;
		Vec2f speed;
		float angle;
		int direction;
	};


public:

	cShot(Vec2f, int);
	~cShot();

	Vec2f getPos();

	void update();
	void draw();

};