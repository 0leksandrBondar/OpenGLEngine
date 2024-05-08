#include "initOpenGl.h"

#include "ShaderProgram.h"
#include "MainWindow.h"
#include "ResourceManager.h"
#include "glm/gtc/type_ptr.hpp"

#include "Windows.h"

void handleInputEvents()
{
	if (GetKeyState('W') < 0)
	{
		MainWindow::GetInstance()->getCamPos().y += MainWindow::GetInstance()->getCamSpeed();
	}
	if (GetKeyState('S') < 0)
	{
		MainWindow::GetInstance()->getCamPos().y -= MainWindow::GetInstance()->getCamSpeed();
	}
	if (GetKeyState('A') < 0 )
	{
		MainWindow::GetInstance()->getCamPos().x -= MainWindow::GetInstance()->getCamSpeed();
	}
	if (GetKeyState('D') < 0)
	{
		MainWindow::GetInstance()->getCamPos().x += MainWindow::GetInstance()->getCamSpeed();
	}
}

int main()
{
  initGLFW();
  MainWindow::GetInstance()->initWindow();
  initGLAD();

  auto triangle = ResourceManager::GetInstance()->loadShaderPrograms("Triangle", "Assets/Shaders/main.vert","Assets/Shaders/main.frag");

  float vertices[] = {
	  -0.5f, -0.5f, 0.0f,
	  0.5f, -0.5f, 0.0f,
	  0.0f,  0.5f, 0.0f
  };

  GLuint vbo = 0;
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  GLuint vao = 0;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

  while (!glfwWindowShouldClose(MainWindow::GetInstance()->GetWindow()))
  {
	  glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	  glClear(GL_COLOR_BUFFER_BIT);

	  handleInputEvents();

	  int viewLoc = glGetUniformLocation(triangle->getProgramId(), "uView");
	  triangle->useShader();

	  glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(MainWindow::GetInstance()->getCameraMatrix()));

	  glBindVertexArray(vao);
	  glDrawArrays(GL_TRIANGLES, 0, 3);

	  glfwSwapBuffers(MainWindow::GetInstance()->GetWindow());

	  glfwPollEvents();
  }

  return 0;
}