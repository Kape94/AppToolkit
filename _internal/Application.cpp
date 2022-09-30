#include "_internal/Application.h"

#include "_internal/OpenGLHelper.h"

#include "InputDefs.h"

//-----------------------------------------------------------------------------

_USING_APP_TOOLKIT_NAMESPACE

//-----------------------------------------------------------------------------

void Application::Initialize()
{
  InitializeContext();
  InitializeApp();
}

//-----------------------------------------------------------------------------

void Application::InitializeContext()
{
  windowContext.Init(1280, 960, "Test");
  OpenGLHelper::Init(1280, 960);

  uiContext.Init(windowContext.GetWindow());
}

//-----------------------------------------------------------------------------

void Application::InitializeApp()
{
  if (appInitializer != nullptr) {
    appInitializer->Initialize();
  }
}

//-----------------------------------------------------------------------------

void Application::Run()
{
  while (ShouldKeepRunning()) {
    ProcessFrame();
  }

  Cleanup();
}

//-----------------------------------------------------------------------------

bool Application::ShouldKeepRunning() const
{
  return isRunning && !windowContext.ShouldClose();
}

//-----------------------------------------------------------------------------

void Application::ProcessFrame()
{
  BeginFrame();

  PresentUI();
  Update();
  Render();

  EndFrame();
}

//-----------------------------------------------------------------------------

void Application::BeginFrame()
{
  OpenGLHelper::Clear(0.0f, 0.0f, 0.0f);
}

//-----------------------------------------------------------------------------

void Application::PresentUI()
{
  uiContext.PresentUI();
}

//-----------------------------------------------------------------------------

void Application::Update()
{
  if (appUpdater != nullptr) {
    appUpdater->Update(*this);
  }
}

//-----------------------------------------------------------------------------

void Application::Render()
{
  if (appRenderer != nullptr) {
    appRenderer->Render();
  }
}

//-----------------------------------------------------------------------------

void Application::EndFrame()
{
  OpenGLHelper::Flush();
  windowContext.Swap();
  windowContext.PollEvents();
  inputStatus.Poll(windowContext.GetWindow());
}

//-----------------------------------------------------------------------------

void Application::Cleanup()
{
  uiContext.Cleanup();
  windowContext.Cleanup();
}

//-----------------------------------------------------------------------------

void Application::SetUiPresenter(
  IuiPresenter* uiPresenter
)
{
  uiContext.SetPresenter(uiPresenter);
}

//-----------------------------------------------------------------------------

void Application::SetAppInitializer(IAppInitializer* _appInitializer)
{
  appInitializer = _appInitializer;
}

//-----------------------------------------------------------------------------

void Application::SetAppRenderer(IAppRenderer* _appRenderer)
{
  appRenderer = _appRenderer;
}

//-----------------------------------------------------------------------------

void Application::SetAppUpdater(IAppUpdater* _appUpdater)
{
  appUpdater = _appUpdater;
}

//-----------------------------------------------------------------------------
// IAppUtils
//-----------------------------------------------------------------------------

bool Application::IsPressed(const Key key)
{
  return inputStatus.IsPressed(key);
}

//-----------------------------------------------------------------------------

bool Application::IsPressed(const MouseButton mouseButton)
{
  return inputStatus.IsPressed(mouseButton);
}

//-----------------------------------------------------------------------------

bool Application::IsReleased(const Key key)
{
  return inputStatus.IsReleased(key);
}

//-----------------------------------------------------------------------------

bool Application::IsReleased(const MouseButton mouseButton)
{
  return inputStatus.IsReleased(mouseButton);
}

//-----------------------------------------------------------------------------

bool Application::IsHold(const Key key)
{
  return inputStatus.IsHold(key);
}

//-----------------------------------------------------------------------------

bool Application::IsHold(const MouseButton mouseButton)
{
  return inputStatus.IsHold(mouseButton);
}

//-----------------------------------------------------------------------------

void Application::Exit()
{
  isRunning = false;
}

//-----------------------------------------------------------------------------

glm::vec2 Application::GetMousePos() const
{
  return windowContext.GetCursorPos();
}

//-----------------------------------------------------------------------------

void Application::SetMousePos(const glm::vec2& pos)
{
  windowContext.SetCursorPos(pos);
}

//-----------------------------------------------------------------------------
