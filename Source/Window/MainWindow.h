#pragma once

#include "ISingleton.h"
#include "OpenGl.h"
#include "glm/glm.hpp"

class MainWindow : public ISingleton<MainWindow>
{
public:
	explicit MainWindow(GLFWwindow* window = nullptr);
	~MainWindow() = default;

	GLFWwindow* GetWindow();

	void initWindow();
	glm::mat4 getCameraMatrix();

	glm::vec2& getCamPos();
	float& getCamSpeed();
private:
	static void glfwWindowSizeCallback(GLFWwindow* window, int width, int height);
	static void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);

private:
	GLFWwindow* _mainWindow;

	float _cameraSpeed = 0.05f;
	glm::vec2 _cameraPos = glm::vec2(0.0f, 0.0f);
};
