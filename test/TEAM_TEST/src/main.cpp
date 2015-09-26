

#include "lib/framework.hpp"
#include <iostream>


enum Window {
	WIDTH = 512,
	HEIGHT = 512
};

enum SceneName {
	TITLE,
	GAME,
};


int main() {

	AppEnv env(Window::WIDTH, Window::HEIGHT, false, true);

	while (env.isOpen()) {

		env.begin();

		env.end();

	}

}
