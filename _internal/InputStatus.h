#ifndef _INPUT_STATUS_H
#define _INPUT_STATUS_H

#include <map>

#include <GLFW/glfw3.h>

#include "AppToolkitDefs.h"
#include "InputDefs.h"

_BEGIN_APP_TOOLKIT_NAMESPACE

class InputStatus {
  public:

    bool IsPressed(const Key key);
    bool IsPressed(const MouseButton mouseButton);

    bool IsReleased(const Key key);
    bool IsReleased(const MouseButton mouseButton);

    bool IsHold(const Key key);
    bool IsHold(const MouseButton mouseButton);

    void Poll(
      GLFWwindow* window
    );

  private:

    std::map<Key, bool> previousKeyState;
    std::map<Key, bool> currentKeyState;

    std::map<MouseButton, bool> previousMouseButtonState;
    std::map<MouseButton, bool> currentMouseButtonState;
};

_END_APP_TOOLKIT_NAMESPACE

#endif
