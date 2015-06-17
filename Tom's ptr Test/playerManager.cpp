
#include "playerManager.h"


cPlayerManager::cPlayerManager(){}


void cPlayerManager::update(AppEnv& app_env){

	Player->update(app_env);
	Shot->setDirection(Player->getDirection());

	if (Player->isPushSpace(app_env)){
		Shot->setPos(Player->getPos());
		Shot->setIsShow();
	}
	if (Shot->isShowShot())
		Shot->update();

}

void cPlayerManager::draw(){

	Player->draw();

	if (Shot->isShowShot())
		Shot->draw();

}
