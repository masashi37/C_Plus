
#pragma once

#include "AppEnv.h"
#include "Common.h"


class Result {

private:

	/*
float x = -WIDTH / 2;
float y = -HEIGHT / 2;
float size_x = WIDTH;
float size_y = HEIGHT;

int cut_x = 0;
int cut_y = 0;
int cut_size_x = 1024;
int cut_size_y = 512;

const int result_lose = 6;
int result_pic_select = 0;

bool Init_flag = false;*/

public:

	Result();

	void setup();
	void update();
	void draw();
	SceneName shift();
	void reset();

};

