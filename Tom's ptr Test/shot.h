
#pragma once

#include "object.h"


typedef std::shared_ptr<class cShot>pShot;
class cShot :public cObject{

private:

	bool is_show_;

public:

	cShot();
	~cShot();

	bool isShowShot();
	void setIsShow();

	Vec2f setPos(Vec2f);

	void setDirection(int);

	void update();
	void draw();

};