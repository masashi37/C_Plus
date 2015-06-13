
#include "player.h"
#include "shot.h"


int main() {

	AppEnv app_env(Window::WIDTH, Window::HEIGHT, false, true);

	pPlayer Player = pPlayer(new cPlayer);
	pShot Shot = pShot(new cShot);

	while (app_env.isOpen()) {

		Player->updata(app_env);
		Shot->setDirection(Player->getDirection());

		if (Player->isPushSpace(app_env)){
			Shot->setPos(Player->getPos());
			Shot->setIsShow();
		}
		if (Shot->isShowShot())
			Shot->updata();


		app_env.setupDraw();


		Player->draw();

		if (Shot->isShowShot())
			Shot->draw();


		app_env.update();

	}

}
