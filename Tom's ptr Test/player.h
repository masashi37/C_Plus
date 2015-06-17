
#pragma once

#include "object.h"


typedef std::shared_ptr<class cPlayer>pPlayer;
class cPlayer :public cObject{
			
public:

	cPlayer();
	~cPlayer();

	Vec2f getPos();
	Vec2f getSize();
	int getDirection();

	bool isPushSpace(AppEnv&);

	void update(AppEnv&);
	void draw();

};