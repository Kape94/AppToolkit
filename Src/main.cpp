#include "GlfwContext.h"
#include "OpenGLHelper.h"
#include "UiContext.h"

#include "imgui.h"

class UiPresenterTest : public IuiPresenter {
  public:
    void Present() override {
      ImGui::SetNextWindowSize(ImVec2(200.0f, 100.0f));

      ImGui::Begin("Hello world!", 0, 
        ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize
      );
      ImGui::Text("Test window \\o/");
      ImGui::End();
    }
};

int main() {
  GlfwContext context;
  context.Init(1280, 960, "Test");
  OpenGLHelper::Init(1280, 960);

  UiPresenterTest uiTest;
  UiContext uiContext;
  uiContext.Init(context.GetWindow());

  uiContext.SetPresenter(&uiTest);
  while (!context.ShouldClose()) {
    OpenGLHelper::Clear(0.0f, 0.0f, 0.0f);
    uiContext.PresentUI();
    OpenGLHelper::Flush();
    context.Swap();
    context.PoolEvents();
  }

  uiContext.Cleanup();
  context.Cleanup();
  return 0;
}