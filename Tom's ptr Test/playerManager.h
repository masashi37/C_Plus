
#pragma once

#include "common.h"

#include "player.h"
#include "shot.h"

typedef std::shared_ptr<class cPlayerManager>pPlayerManager;
class cPlayerManager{

private:
	pPlayer Player = pPlayer(new cPlayer);

	std::vector<pShot>shot;
public:

	cPlayerManager() = default;

	void update(AppEnv&);
	void draw();
};