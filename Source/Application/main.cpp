#include "initOpenGl.h"

#include "ShaderProgram.h"
#include "Texture2D.h"
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
  auto texture = ResourceManager::GetInstance()->loadTexture("Triangle", "Assets/Textures/pexels-iriser-1366957.jpg");

  float vertices[] = {
	  -0.5f, -0.5f, 0.0f, //left
	  0.5f, -0.5f, 0.0f, // right
	  0.0f,  0.5f, 0.0f // top
  };

  float textureCoord[] = {
	  0.0f, 0.0f,
	  1.0f, 0.0f,
	  0.5f,  1.0f
  };

  GLuint vbo = 0;
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


  GLuint textureVBO = 0;
  glGenBuffers(1, &textureVBO);
  glBindBuffer(GL_ARRAY_BUFFER, textureVBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(textureCoord), textureCoord, GL_STATIC_DRAW);

  GLuint vao = 0;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

  glEnableVertexAttribArray(1);
  glBindBuffer(GL_ARRAY_BUFFER, textureVBO);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

  triangle->useShader();
  triangle->setID("tex",0);

  while (!glfwWindowShouldClose(MainWindow::GetInstance()->GetWindow()))
  {
	  glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	  glClear(GL_COLOR_BUFFER_BIT);

	  handleInputEvents();

	  int viewLoc = glGetUniformLocation(triangle->getProgramId(), "uView");
	  triangle->useShader();

	  glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(MainWindow::GetInstance()->getCameraMatrix()));

	  glBindVertexArray(vao);
	  texture->bind();
	  glDrawArrays(GL_TRIANGLES, 0, 3);

	  glfwSwapBuffers(MainWindow::GetInstance()->GetWindow());

	  glfwPollEvents();
  }

  return 0;
}