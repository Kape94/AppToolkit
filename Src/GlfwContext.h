#ifndef _GLFW_CONTEXT_H
#define _GLFW_CONTEXT_H

#include <string>

class GLFWwindow;

class GlfwContext {
  public:

    void Init(
      const unsigned _screenWidth,
      const unsigned _screenHeight,
      const std::string& windowTitle
    );

    bool ShouldClose() const;

    void PoolEvents();

    void Swap();

    void Cleanup();

  private:

    GLFWwindow* window = nullptr;
};

#endif
