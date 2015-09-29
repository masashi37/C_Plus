
#pragma once

#include "AppEnv.h"
#include "Common.h"


class Game {

private:

	enum CharaTextureName {
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


	enum MapText {
		MAP_TYPE01,

		MAP_TEXT_MAX,
	};
	std::ifstream* map_type_list_[MAP_TEXT_MAX];

	struct Map {
		int state;

		Vec2f pos;
		int size;
		Vec2i cut_pos;
		Vec2i cut_size;
	};
	enum {
		MAP_LENGTH = 10,
		MAP_WIDE = 120,
	};
	Map map_[MAP_LENGTH][MAP_WIDE];

	enum BlockType {
		AIR,
		FLOOR,
		GROUND,
		TRANSFORMATION,
		CONCRETE,
		RED_CARPET,
		GOAL,
		PRINCE,
	};


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

