
#pragma once

#include "AppEnv.h"
#include "Common.h"


class Game {

private:

	enum {
		ALICE,
		CINDERELLA,
		KAGUYA,
		MUCH_GIRL,
		RED_HOOD,
		SNOW_WHITE,

		ALICE_DASH,
		CINDERELLA_DASH,
		KAGUYA_DASH,
		MUCH_GIRL_DASH,
		RED_HOOD_DASH,
		SNOW_WHITE_DASH,

		CHARA_MAX,
	};
	Texture* chara_list_[CHARA_MAX];

	TextureObject chara_[CHARA_MAX];

	TextureObject prince_;

	int chara_selecter_;

public:

	Game();

	void setChara(int);

	void setup();
	void update();
	void draw();
	SceneName shift();
	void reset();

};

