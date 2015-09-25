
#pragma once

#include "Title.h"
#include "Game.h"
#include "Result.h"


class Scene {

private:

	SceneName scene_changer_;

	int count;

	Title title;
	Game game;
	Result result;

public:

	Scene();

	void update();
	void draw();
	void shift();

};

