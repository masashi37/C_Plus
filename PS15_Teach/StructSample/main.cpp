
//15生のGameTemplateで言う lib/framework.hpp
#include "lib/defines.hpp"
#include "lib/appEnv.hpp"

//ランダムの呼び出し
#include "lib/random.hpp"
#include <ctime>


// アプリのウインドウサイズ
enum Window {
	WIDTH = 500,
	HEIGHT = 500
};


//ランダム
Random random;

//構造体の名前は大文字始まりが良い（※1）
struct Object{

	Vec2f pos;					//ポジション
	Vec2f size;					//サイズ
	Vec2f speed;				//速度
	float red, green, blue;		//色
	//共通の要素を追加したいならこの中に書けば追加可能

}/*ここに書いても作れる*/;


//色を変える関数
void colorChange(float& r, float& g, float& b){
	r = random.fromZeroToOne();
	g = random.fromZeroToOne();
	b = random.fromZeroToOne();
}


// メインプログラム
int main() {


	// アプリウインドウの準備
	AppEnv env(WIDTH, HEIGHT);

	//ランダムパターンが同じにならないように
	random.setSeed(u_int(time(nullptr)));

	//Object型のobjを作成
	enum {
		//enum で obj の最大値を設定
		//配列で作る場合：数を変えたいならこの数字を変えるだけ
		OBJ_MAX = 5
	};
	Object obj[OBJ_MAX];

	//初期化
	for (int i = 0; i < OBJ_MAX; ++i){
		obj[i] = {
			Vec2f(0, 0), Vec2f(50, 50),
			Vec2f(random.fromFirstToLast(-5, 5), random.fromFirstToLast(-5, 5)),
			random.fromZeroToOne(), random.fromZeroToOne(), random.fromZeroToOne()
		};
	}


	while (env.isOpen()){


		for (int i = 0; i < OBJ_MAX; ++i){
			//objに速度を加える
			//Vec2f + Vec2f が可能（ (pos.x + speed.x), (pos.y + speed.y) ）
			obj[i].pos += obj[i].speed;

			//壁とobjの当たり判定(当たったら反射)
			if (obj[i].pos.x() < -WIDTH / 2){						//左の壁
				obj[i].speed.x() = random.fromFirstToLast(2, 5);
				colorChange(obj[i].red, obj[i].green, obj[i].blue);
			}
			if (obj[i].pos.x() + obj[i].size.x() > WIDTH / 2){		//右の壁
				obj[i].speed.x() = random.fromFirstToLast(-5, -2);
				colorChange(obj[i].red, obj[i].green, obj[i].blue);
			}
			if (obj[i].pos.y() < -HEIGHT / 2){						//下の壁
				obj[i].speed.y() = random.fromFirstToLast(2, 5);
				colorChange(obj[i].red, obj[i].green, obj[i].blue);
			}
			if (obj[i].pos.y() + obj[i].size.y() > HEIGHT / 2){		//上の壁
				obj[i].speed.y() = random.fromFirstToLast(-5, -2);
				colorChange(obj[i].red, obj[i].green, obj[i].blue);
			}

		}


		// 描画準備
		env.setupDraw();



		//描画
		for (int i = 0; i < OBJ_MAX; ++i){
			drawFillBox(obj[i].pos.x(), obj[i].pos.y(),
				obj[i].size.x(), obj[i].size.y(), Color(obj[i].red, obj[i].green, obj[i].blue));
		}


		// 画面更新
		env.update();

	}

}

//※1：プログラムには命名規則があって「一般的」な書き方が決まっている。詳細は略。
//※2：構造体の要素を取り出す時は 名前.要素 で

//何か分からなかったらいつでもどうぞ
