#ifndef _I_APP_H
#define _I_APP_H

#include "AppToolkitDefs.h"
#include "IAppInitializer.h"
#include "IAppRenderer.h"
#include "IAppUpdater.h"
#include "IAppUtils.h"
#include "IuiPresenter.h"

_BEGIN_APP_TOOLKIT_NAMESPACE

class IApp {
  public:
    virtual ~IApp() = default;

    virtual void Initialize() = 0;
    virtual void Run() = 0;

    virtual void SetUiPresenter(IuiPresenter* uiPresenter) = 0;
    virtual void SetAppInitializer(IAppInitializer* _appInitializer) = 0;
    virtual void SetAppRenderer(IAppRenderer* _appRenderer) = 0;
    virtual void SetAppUpdater(IAppUpdater* _appUpdater) = 0;
};

_END_APP_TOOLKIT_NAMESPACE

#endif
