#ifndef _APPLICATION_H
#define _APPLICATION_H

#include "IAppInitializer.h"
#include "IAppRenderer.h"
#include "IAppUpdater.h"
#include "IAppUtils.h"
#include "InputStatus.h"
#include "UiContext.h"

#include "GlfwContext.h"

class Application : 
  public IAppUtils // implements
{
  public:

    Application();

    void Run();

    void SetUiPresenter(IuiPresenter* uiPresenter);
    void SetAppInitializer(IAppInitializer* _appInitializer);
    void SetAppRenderer(IAppRenderer* _appRenderer);
    void SetAppUpdater(IAppUpdater* _appUpdater);

  private:

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

    void InitializeContext();

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

#endif
