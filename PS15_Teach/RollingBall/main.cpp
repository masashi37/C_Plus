
#include "common.h"
#include "ball.h"

int main() {

	AppEnv env(WIDTH, HEIGHT);

	Ball Ball;

	while (env.isOpen()) {

		Ball.update();

		env.begin();

		Ball.draw();

		env.end();

	}

}
