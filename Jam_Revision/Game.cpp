
#include "Game.h"


Game::Game(){
	map.load();

	map_speed_ = Vec2f(-3.0f, 0);
}


void Game::setChara(int select_chara_num) {
	chara_selecter_ = select_chara_num;
}


void Game::setup() {

	map.setup();

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

}

void Game::update() {

	map.setPos(map_speed_);

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
	map.draw();
}

SceneName Game::shift() {

	return SceneName::GAME;
}

void Game::reset() {

}

