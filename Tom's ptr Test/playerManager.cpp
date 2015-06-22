
#include "playerManager.h"
#include <iostream>

void cPlayerManager::update(AppEnv& app_env){

	Player->update(app_env);

	if (Player->isPushSpace(app_env))
		shot.push_back(pShot(new cShot(Player->getPos(), Player->getDirection())));

	auto shot_it = shot.begin();
	while (shot_it != shot.end()){
		(*shot_it)->update();

		if ((*shot_it)->getPos().x() < -WIDTH / 2 || (*shot_it)->getPos().x() > WIDTH / 2 ||
			(*shot_it)->getPos().y() < -HEIGHT / 2 || (*shot_it)->getPos().y() > HEIGHT / 2){
			shot_it = shot.erase(shot_it++);
		}

		std::cout << shot.size() << std::endl;

		shot_it++;
	}

}

void cPlayerManager::draw(){

	Player->draw();

	for (auto& shots : shot){
		shots->draw();
	}

}
