
#include "playerManager.h"


int main() {

	AppEnv app_env(Window::WIDTH, Window::HEIGHT, false, true);

	pPlayerManager PlayerManager = pPlayerManager(new cPlayerManager);

	while (app_env.isOpen()){

		PlayerManager->update(app_env);

		app_env.setupDraw();

		PlayerManager->draw();

		app_env.update();

	}

}
