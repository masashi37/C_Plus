
#include <GLFW/glfw3.h>				//�V�X�e����`�̃C���N���[�h


void drawPoint(
	float x, float y,
	float size,
	float red, float green, float blue, float alpha){

	//�`�悷��u�_�v��X���W��Y���W��z��ŗp��
	const GLfloat vtx[] = { x, y };

	//�`��Ɏg�����_�̔z���OpenGL�Ɏw������
	glVertexPointer(2, GL_FLOAT, 0, vtx);

	//�`�悷��u�_�v�̑傫�����w��
	glPointSize(size);

	//�`�悷��u�_�v�̐F�̐�����
	//���ꂼ��0.0�`1.0�Ŏw��
	//glColor4f(��, ��, ��, �A���t�@)
	glColor4f(red, green, blue, alpha);

	//----------------------------------------------------

	//�u�_�v�̌`���~��
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//���_�z��ŕ`�悷�郂�[�h�ɐ؂�ւ���
	//�u�_�v�̕`����J��
	glEnableClientState(GL_VERTEX_ARRAY);
	glDrawArrays(GL_POINTS, 0, 1);
	//�`�悪�I�������`�惂�[�h�����ɖ߂�
	glDisableClientState(GL_VERTEX_ARRAY);

}

void drawLine(
	float start_x, float start_y, float end_x, float end_y,
	float size,
	float red, float green, float blue, float alpha){

	//�`�悷��u�_�v��X���W��Y���W��z��ŗp��
	const GLfloat vtx[] = { start_x, start_y, end_x, end_y };

	//�`��Ɏg�����_�̔z���OpenGL�Ɏw������
	glVertexPointer(2, GL_FLOAT, 0, vtx);

	//�`�悷��u�_�v�̑傫�����w��
	glLineWidth(size);

	//�`�悷��u�_�v�̐F�̐�����
	//���ꂼ��0.0�`1.0�Ŏw��
	//glColor4f(��, ��, ��, �A���t�@)
	glColor4f(red, green, blue, alpha);

	//----------------------------------------------------

	//���_�z��ŕ`�悷�郂�[�h�ɐ؂�ւ���
	//�u�_�v�̕`����J��
	glEnableClientState(GL_VERTEX_ARRAY);
	glDrawArrays(GL_LINE, 0, 2);
	//�`�悪�I�������`�惂�[�h�����ɖ߂�
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

		//�`��o�b�t�@��h��ׂ��F�̐�����
		//���ꂼ��0.0�`1.0�Ŏw��
		//glClearColor(��, ��, ��, �A���t�@)
		glClearColor(0.0f, 0.0f, 1.0f, 0.0f);

		//�`��o�b�t�@��h��ׂ�
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

//glfwInit();		//GLFW�̏�����