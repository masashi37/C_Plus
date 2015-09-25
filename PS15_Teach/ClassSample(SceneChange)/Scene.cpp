
#include "Scene.h"


Scene::Scene() {
	scene_changer_ = TITLE;
}

void Scene::update() {

	switch (scene_changer_) {

	case TITLE:
		title.update();
		break;

	case GAME:
		std::cout << "game : " << count << std::endl;
		count = game.getCount();
		game.update();
		break;

	case RESULT:
		std::cout << "result : " << count << std::endl;
		result.update();
		break;

	}

}

void Scene::draw() {

	switch (scene_changer_) {

	case TITLE:
		title.draw();
		break;

	case GAME:
		game.draw();
		break;

	case RESULT:
		result.draw();
		break;

	}

}

void Scene::shift() {

	switch (scene_changer_) {

	case TITLE:
		scene_changer_ = title.shift();
		break;

	case GAME:
		scene_changer_ = game.shift();
		break;

	case RESULT:
		scene_changer_ = result.shift();
		break;

	}

}

