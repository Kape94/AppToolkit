#ifndef _UI_CONTEXT_H
#define _UI_CONTEXT_H

#include <GLFW/glfw3.h>

#include "IuiPresenter.h"

class UiContext {
  public:

    void Init(
      GLFWwindow* window
    );

    void SetPresenter(
      IuiPresenter* _presenter
    );
    void PresentUI();

    void Cleanup();

  private:

    IuiPresenter* uiPresenter = nullptr;
};

#endif
