
#include "Result.h"


Result::Result() {
}

void Result::update() {

}

void Result::draw() {
	App::env->bgColor(Color(0, 0, 1));
}

SceneName Result::shift() {
	if (App::env->isPushKey('D'))
	return SceneName::TITLE;

	return SceneName::RESULT;
}

 