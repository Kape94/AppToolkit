#include "GlfwContext.h"

#include <GLFW/glfw3.h>

//-----------------------------------------------------------------------------

void GlfwContext::Init(
  const unsigned _screenWidth, 
  const unsigned _screenHeight, 
  const std::string& windowTitle
)
{
  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  this->window = glfwCreateWindow(
    _screenWidth, _screenHeight, windowTitle.c_str(), nullptr, nullptr
  );
  glfwMakeContextCurrent(this->window);
}

//-----------------------------------------------------------------------------

bool GlfwContext::ShouldClose() const
{
  return glfwWindowShouldClose(this->window);
}

//-----------------------------------------------------------------------------

void GlfwContext::PoolEvents()
{
  glfwPollEvents();
}

//-----------------------------------------------------------------------------

void GlfwContext::Swap()
{
  glfwSwapBuffers(this->window);
}

//-----------------------------------------------------------------------------

void GlfwContext::Cleanup()
{
  glfwDestroyWindow(this->window);
  glfwTerminate();
}

//-----------------------------------------------------------------------------

GLFWwindow* GlfwContext::GetWindow()
{
  return this->window;
}

//-----------------------------------------------------------------------------
