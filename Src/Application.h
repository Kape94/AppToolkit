#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <memory>

#include "GlfwContext.h"
#include "InputStatus.h"
#include "UiContext.h"

class Application {
  public:

    Application();

    void Run();

  private:

    GlfwContext windowContext;
    UiContext uiContext;
    std::unique_ptr<IuiPresenter> uiPresenter = nullptr;

    InputStatus inputStatus;
};

#endif
