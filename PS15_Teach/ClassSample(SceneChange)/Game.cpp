
#include "Game.h"


Game::Game() {
	count = 0;
}


int Game::getCount() {
	return count;
}


void Game::update() {

	if (App::env->isPushKey(GLFW_KEY_SPACE))
		count++;

}

void Game::draw() {
	App::env->bgColor(Color(0, 1, 0));
}

SceneName Game::shift() {
	if (App::env->isPushKey('S'))
		return SceneName::RESULT;

	return SceneName::GAME;
}

