#ifndef _I_APP_INITIALIZER_H
#define _I_APP_INITIALIZER_H

#include "AppToolkitDefs.h"

_BEGIN_APP_TOOLKIT_NAMESPACE

class IAppInitializer {
  public:
    virtual ~IAppInitializer() = default;

    virtual void Initialize() = 0;
};

_END_APP_TOOLKIT_NAMESPACE

#endif
