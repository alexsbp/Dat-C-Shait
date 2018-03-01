
#include <GLFW\glfw3.h>
#include <iostream>
using namespace std;




void size_resize_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

int main()
{
	glfwInit(); //initialisering af glfw
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	GLFWwindow* window = glfwCreateWindow(800, 600, "MyGLFWGLAD1", NULL, NULL);

	if (window == NULL)
	{
		cout << "kunne ikke oprette openGL vindue";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window); //sørger for at openGL bruger vinduet som renderings context

	glViewport(0, 0, 800, 600);

	glfwSetFramebufferSizeCallback(window, size_resize_callback);

	while (!glfwWindowShouldClose(window)) // gameloop (imens vinduet er åbent, køre følgende kode)
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //sætter baggrundsfarve
		glClear(GL_COLOR_BUFFER_BIT); //nustiller baggrunden til baggrundsfarven


		glBegin(GL_TRIANGLES);
		glVertex3f(-0.5f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.5f, 0.0f);
		glVertex3f(0.5f, 0.0f, 0.0f);
		glEnd();



		glfwSwapBuffers(window);
		glfwPollEvents();
	}



	glfwTerminate();
	return 0;
}