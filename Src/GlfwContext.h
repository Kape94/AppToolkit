#ifndef _GLFW_CONTEXT_H
#define _GLFW_CONTEXT_H

#include <string>

#include <GLFW/glfw3.h>

class GlfwContext {
  public:

    void Init(
      const unsigned _screenWidth,
      const unsigned _screenHeight,
      const std::string& windowTitle
    );

    bool ShouldClose() const;

    void PollEvents();

    void Swap();

    void Cleanup();

    GLFWwindow* GetWindow();

  private:

    GLFWwindow* window = nullptr;
};

#endif
