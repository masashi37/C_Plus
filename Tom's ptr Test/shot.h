
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
		bool is_show;
	};

	std::vector<ShotDate>shot;
	ShotDate shot_init;

public:

	cShot();
	~cShot();

	void create(bool, Vec2f, int);

	void update();
	void draw();

};