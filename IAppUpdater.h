#ifndef _I_APP_UPDATER_H
#define _I_APP_UPDATER_H

#include "AppToolkitDefs.h"
#include "IAppUtils.h"

_BEGIN_APP_TOOLKIT_NAMESPACE

class IAppUpdater {
  public:
    virtual ~IAppUpdater() = default;

    virtual void Update(IAppUtils& appUtils) = 0;
};

_END_APP_TOOLKIT_NAMESPACE

#endif
