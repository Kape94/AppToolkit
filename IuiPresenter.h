#ifndef _I_UI_PRESENTER_H
#define _I_UI_PRESENTER_H

#include "imgui.h"

class IuiPresenter {
  public:

    virtual ~IuiPresenter() = default;

    virtual void Present() = 0;
};

#endif