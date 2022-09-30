#ifndef _APPLICATION_H
#define _APPLICATION_H

#include "AppToolkitDefs.h"
#include "IApp.h"

#include "_internal/InputStatus.h"
#include "_internal/UiContext.h"

#include "_internal/GlfwContext.h"

_BEGIN_APP_TOOLKIT_NAMESPACE

class Application : 
  /*implements*/ public IAppUtils,
  /*implements*/ public IApp
{
  public:

    Application() = default;

  private:

    // -----------------------IApp-----------------------------------
    void Initialize(
      const WindowProperties& windowProperties = WindowProperties()
    ) override;

    void Run() override;

    void SetUiPresenter(IuiPresenter* uiPresenter) override;
    void SetAppInitializer(IAppInitializer* _appInitializer) override;
    void SetAppRenderer(IAppRenderer* _appRenderer) override;
    void SetAppUpdater(IAppUpdater* _appUpdater) override;
    // -----------------------IApp-----------------------------------

    // -----------------------IAppUtils------------------------------
    bool IsPressed(const Key key) override;
    bool IsPressed(const MouseButton mouseButton) override;

    bool IsReleased(const Key key) override;
    bool IsReleased(const MouseButton mouseButton) override;

    bool IsHold(const Key key) override;
    bool IsHold(const MouseButton mouseButton) override;

    void Exit() override;

    glm::vec2 GetMousePos() const override;
    void SetMousePos(const glm::vec2& pos) override;
    // -----------------------IAppUtils------------------------------

    void InitializeContext(
      const WindowProperties& windowProperties
    );

    void InitializeApp();
    bool ShouldKeepRunning() const;
    void ProcessFrame();
    void BeginFrame();
    void PresentUI();
    void Update();
    void Render();
    void EndFrame();
    void Cleanup();

    GlfwContext windowContext;
    UiContext uiContext;

    InputStatus inputStatus;

    IAppInitializer* appInitializer = nullptr;
    IAppRenderer* appRenderer = nullptr;
    IAppUpdater* appUpdater = nullptr;

    bool isRunning = true;
};

_END_APP_TOOLKIT_NAMESPACE

#endif
