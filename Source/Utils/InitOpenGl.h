#pragma once

#include "OpenGl.h"
#include "iostream"

void initGLFW()
{
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void initGLAD()
{
  if (!gladLoadGL())
  {
    std::cout << "can't load GLAD!";
  }
}