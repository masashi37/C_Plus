
#include "Title.h"


Title::Title() {
}

void Title::update() {

}

void Title::draw() {
	App::env->bgColor(Color(1, 0, 0));
}

SceneName Title::shift() {
	if (App::env->isPushKey('A'))
		return SceneName::GAME;

	return SceneName::TITLE;

}

