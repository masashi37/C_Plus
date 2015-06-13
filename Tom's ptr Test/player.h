
#pragma once

#include "object.h"


class cPlayer;
typedef std::shared_ptr<cPlayer>pPlayer;
class cPlayer :public cObject{

private:

	Texture player_pic;
		
public:

	cPlayer();
	~cPlayer();

	Vec2f getPos();
	Vec2f getSize();
	int getDirection();

	bool isPushSpace(AppEnv&);

	void updata(AppEnv&);
	void draw();

};