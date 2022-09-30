#include "GlfwContext.h"

//-----------------------------------------------------------------------------

void GlfwContext::Init(
  const unsigned _screenWidth, 
  const unsigned _screenHeight, 
  const std::string& windowTitle
)
{
  glfwInit();

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

void GlfwContext::PollEvents()
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
