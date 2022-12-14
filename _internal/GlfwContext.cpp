#include "_internal/GlfwContext.h"

//-----------------------------------------------------------------------------

_USING_APP_TOOLKIT_NAMESPACE

//-----------------------------------------------------------------------------

void GlfwContext::Init(
  const WindowProperties& windowProperties
)
{
  glfwInit();

  const bool isFullscreen = windowProperties.fullscreen;
  auto monitor = isFullscreen ? glfwGetPrimaryMonitor() : nullptr;
  this->window = glfwCreateWindow(
    windowProperties.width, 
    windowProperties.height, 
    windowProperties.name.c_str(), 
    monitor, 
    nullptr
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

glm::vec2 GlfwContext::GetCursorPos() const
{
  double xPos, yPos;
  glfwGetCursorPos(window, &xPos, &yPos);
  return { xPos, yPos };
}

//-----------------------------------------------------------------------------

void GlfwContext::SetCursorPos(const glm::vec2& pos)
{
  glfwSetCursorPos(window, pos.x, pos.y);
}

//-----------------------------------------------------------------------------
