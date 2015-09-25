
#pragma once

#include "AppEnv.h"
#include "Common.h"


class Game {

private:

	int count;

public:

	Game();

	int getCount();

	void update();
	void draw();
	SceneName shift();

};

