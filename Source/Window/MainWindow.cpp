#include "MainWindow.h"

#include "glm/gtc/matrix_transform.hpp"

#include <iostream>

MainWindow::MainWindow(GLFWwindow* window) : _mainWindow {window}
{
}

void MainWindow::initWindow()
{
	if (GLFWwindow* window = glfwCreateWindow(1400, 1000, "OpenGL", nullptr, nullptr))
	{
		glfwSetWindowSizeCallback(window, glfwWindowSizeCallback);
		glfwSetKeyCallback(window, glfwKeyCallback);
		glfwMakeContextCurrent(window);
		_mainWindow = window;
	}
	else
	{
		std::cerr << "creation window failed!";
	}
}

GLFWwindow* MainWindow::GetWindow()
{
	return _mainWindow;
}

void MainWindow::glfwWindowSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void MainWindow::glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE )
	{
		glfwSetWindowShouldClose(window, true);
	}
}

glm::mat4 MainWindow::getCameraMatrix()
{
	glm::mat4 view = glm::mat4(1.f);
	view = glm::translate(view, glm::vec3(_cameraPos.x, _cameraPos.y, 0.0f));
	view = glm::inverse(view);
	return view;
}

glm::vec2& MainWindow::getCamPos()
{
	return _cameraPos;
}

float& MainWindow::getCamSpeed()
{
	return _cameraSpeed;
}