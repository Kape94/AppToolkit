#ifndef _WINDOW_PROPERTIES_H
#define _WINDOW_PROPERTIES_H

#include <string>

_BEGIN_APP_TOOLKIT_NAMESPACE

struct WindowProperties {
  unsigned width = 800;
  unsigned height = 600;
  std::string name = "New window";
  bool fullscreen = false;
};

_END_APP_TOOLKIT_NAMESPACE

#endif
