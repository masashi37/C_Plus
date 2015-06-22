
#include "playerManager.h"
#include <iostream>

void cPlayerManager::update(AppEnv& app_env){

	Player->update(app_env);

	if (Player->isPushSpace(app_env))
		shot.push_back(pShot(new cShot(Player->getPos(), Player->getDirection())));

	for (int i = 0; i < shot.size(); ++i){
		shot[i]->update();

		if (shot[i]->getPos().x() < -WIDTH / 2 || shot[i]->getPos().x() > WIDTH / 2 ||
			shot[i]->getPos().y() < -HEIGHT / 2 || shot[i]->getPos().y() > HEIGHT / 2){
			shot.erase(shot.begin());
		}

		std::cout << shot.size()<<std::endl;
	}

}

void cPlayerManager::draw(){

	Player->draw();

	for (auto& shots : shot){
		shots->draw();
	}

}
