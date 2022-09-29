#ifndef _I_APP_UPDATER_H
#define _I_APP_UPDATER_H

#include "IAppUtils.h"

class IAppUpdater {
  public:
    virtual ~IAppUpdater() = default;

    virtual void Update(IAppUtils& appUtils) = 0;
};

#endif
