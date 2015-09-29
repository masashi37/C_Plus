
#include "Game.h"


Game::Game() {
}


void Game::setChara(int select_chara_num) {
	chara_selecter_ = select_chara_num;
}


void Game::setup() {

	//‰æ‘œ---------------------------------------------
	const char* texture_name[CHARA_MAX]{
		"res/Texture/Chara/alice.png",
		"res/Texture/Chara/cinderella.png",
		"res/Texture/Chara/kaguya.png",
		"res/Texture/Chara/much.png",
		"res/Texture/Chara/red_zukin.png",
		"res/Texture/Chara/snow_white.png",

		"res/Texture/Chara/alice_evo.png",
		"res/Texture/Chara/cinderella_evo.png",
		"res/Texture/Chara/kaguya_evo.png",
		"res/Texture/Chara/much_evo.png",
		"res/Texture/Chara/red_zukin_evo.png",
		"res/Texture/Chara/snow_white_evo.png",
	};
	for (int index = 0; index < CHARA_MAX; ++index) {
		chara_list_[index] = new Texture(texture_name[index]);
	}

	prince_.pic =
		Texture("res/Texture/Chara/prince.png");


	//ƒ}ƒbƒv---------------------------------------------
	const char* text_name[MAP_TEXT_MAX]{
		"res/mapType/map_type01.txt"
	};
	for (int index = 0; index < MAP_TEXT_MAX; ++index) {
		map_type_list_[index] = new std::ifstream(text_name[index]);
	}

	for (int y = 0; y < MAP_LENGTH; y++) {
		for (int x = 0; x < MAP_WIDE; x++) {

			map_[y][x].size = 100;

			map_[y][x].pos.x() =
				-WIDTH / 2 + (map_[y][x].size * x) -
				((map_[y][x].size * MAP_WIDE) * y);
			map_[y][x].pos.y() =
				HEIGHT / 2 - map_[y][x].size -
				(map_[y][x].size * y);

			map_[y][x].cut_pos =
				Vec2i(0, 0);
			map_[y][x].cut_size=
				Vec2i(512, 512);

			

		}
	}

}

void Game::update() {

	/*
	//BGM Ä¶
	if (music_flag.stage_music1_flag == false){
		music_list[STAGE_MUSIC1]->play();
		charaInit();
		music_flag.stage_music1_flag = true;
	}
	*/

}

void Game::draw() {
}

SceneName Game::shift() {

	return SceneName::GAME;
}

void Game::reset() {

}

