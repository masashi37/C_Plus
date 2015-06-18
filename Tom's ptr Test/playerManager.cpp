
#include "playerManager.h"


cPlayerManager::cPlayerManager(){}


void cPlayerManager::update(AppEnv& app_env){

	Player->update(app_env);

	if (Player->isPushSpace(app_env))
		Shot->create(true, Player->getPos(), Player->getDirection());

	Shot->update();

}

void cPlayerManager::draw(){

	Player->draw();

	Shot->draw();

}
