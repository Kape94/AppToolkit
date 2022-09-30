#ifndef _GLFW_CONTEXT_H
#define _GLFW_CONTEXT_H

#include "AppToolkitDefs.h"

#include <string>

#include <GLFW/glfw3.h>
#include <glm/vec2.hpp>

_BEGIN_APP_TOOLKIT_NAMESPACE

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

    glm::vec2 GetCursorPos() const;
    void SetCursorPos(const glm::vec2& pos);

  private:

    GLFWwindow* window = nullptr;
};

_END_APP_TOOLKIT_NAMESPACE

#endif
