#include "Application.h"

#include "OpenGLHelper.h"

#include "InputDefs.h"

#include "imgui.h"
class UiPresenterTest : public IuiPresenter {
public:

  virtual ~UiPresenterTest() = default;

  void Present() override {
    ImGui::SetNextWindowSize(ImVec2(200.0f, 100.0f));

    ImGui::Begin("Hello world!", 0,
      ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize
    );
    ImGui::Text("Test window \\o/");
    ImGui::End();
  }
};

//-----------------------------------------------------------------------------

Application::Application()
{
  windowContext.Init(1280, 960, "Test");
  OpenGLHelper::Init(1280, 960);

  uiPresenter = std::make_unique<UiPresenterTest>();
  
  uiContext.Init(windowContext.GetWindow());
  uiContext.SetPresenter(uiPresenter.get());
}

//-----------------------------------------------------------------------------

void Application::Run()
{
  while (!windowContext.ShouldClose()) {
    OpenGLHelper::Clear(0.0f, 0.0f, 0.0f);

    uiContext.PresentUI();

    if (inputStatus.IsHold(Key::ESC)) {
      break;
    }

    OpenGLHelper::Flush();
    windowContext.Swap();
    windowContext.PollEvents();
    inputStatus.Poll(windowContext.GetWindow());
  }

  uiContext.Cleanup();
  windowContext.Cleanup();
}

//-----------------------------------------------------------------------------
