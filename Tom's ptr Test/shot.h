
#pragma once

#include "object.h"


class cShot;
typedef std::shared_ptr<cShot>pShot;
class cShot :public cObject{

private:

	Texture shot_pic;

	bool is_show;

public:

	cShot();
	~cShot();

	bool isShowShot();
	void setIsShow();

	Vec2f setPos(Vec2f);

	void setDirection(int);

	void updata();
	void draw();

};