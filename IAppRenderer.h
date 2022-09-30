#ifndef _I_APP_RENDERER_H
#define _I_APP_RENDERER_H

#include "AppToolkitDefs.h"

#include <gl/glew.h>

_BEGIN_APP_TOOLKIT_NAMESPACE

class IAppRenderer {
  public:
    virtual ~IAppRenderer() = default;

    virtual void Render() = 0;
};

_END_APP_TOOLKIT_NAMESPACE

#endif
