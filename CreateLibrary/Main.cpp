
#include <GLFW/glfw3.h>				//システム定義のインクルード


void drawPoint(
	float x, float y,
	float size,
	float red, float green, float blue, float alpha){

	//描画する「点」のX座標とY座標を配列で用意
	const GLfloat vtx[] = { x, y };

	//描画に使う頂点の配列をOpenGLに指示する
	glVertexPointer(2, GL_FLOAT, 0, vtx);

	//描画する「点」の大きさを指定
	glPointSize(size);

	//描画する「点」の色の成分を
	//それぞれ0.0～1.0で指定
	//glColor4f(赤, 緑, 青, アルファ)
	glColor4f(red, green, blue, alpha);

	//----------------------------------------------------

	//「点」の形を円に
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//頂点配列で描画するモードに切り替えて
	//「点」の描画を開発
	glEnableClientState(GL_VERTEX_ARRAY);
	glDrawArrays(GL_POINTS, 0, 1);
	//描画が終わったら描画モードを元に戻す
	glDisableClientState(GL_VERTEX_ARRAY);

}

void drawLine(
	float start_x, float start_y, float end_x, float end_y,
	float size,
	float red, float green, float blue, float alpha){

	//描画する「点」のX座標とY座標を配列で用意
	const GLfloat vtx[] = { start_x, start_y, end_x, end_y };

	//描画に使う頂点の配列をOpenGLに指示する
	glVertexPointer(2, GL_FLOAT, 0, vtx);

	//描画する「点」の大きさを指定
	glLineWidth(size);

	//描画する「点」の色の成分を
	//それぞれ0.0～1.0で指定
	//glColor4f(赤, 緑, 青, アルファ)
	glColor4f(red, green, blue, alpha);

	//----------------------------------------------------

	//頂点配列で描画するモードに切り替えて
	//「点」の描画を開発
	glEnableClientState(GL_VERTEX_ARRAY);
	glDrawArrays(GL_LINE, 0, 2);
	//描画が終わったら描画モードを元に戻す
	glDisableClientState(GL_VERTEX_ARRAY);

}


int main(void){

	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window){
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window)){

		/* Render here */

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		//----------------------------------

		//描画バッファを塗り潰す色の成分を
		//それぞれ0.0～1.0で指定
		//glClearColor(赤, 緑, 青, アルファ)
		glClearColor(0.0f, 0.0f, 1.0f, 0.0f);

		//描画バッファを塗り潰す
		glClear(GL_COLOR_BUFFER_BIT);

		drawPoint(0.5f, 0.0f,
			10.0f,
			1.0f, 1.0f, 1.0f, 1.0f);

		drawPoint(0.0f, 0.0f,
			10.0f,
			1.0f, 1.0f, 1.0f, 1.0f);
		
		drawLine(-0.5f, 0.5f, 0.5f, -0.5f,
			5.0f,
			1.0f, 0.0f, 0.0f, 1.0f);
	}

	glfwTerminate();
	return 0;
}

//glfwInit();		//GLFWの初期化