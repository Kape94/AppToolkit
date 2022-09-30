#include "Application.h"

class AppTest : public IuiPresenter, public IAppUpdater, public IAppRenderer {
public:

  virtual ~AppTest() = default;

  void Present() override {
    ImGui::SetNextWindowSize(ImVec2(200.0f, 100.0f));

    ImGui::Begin("Hello world!", 0,
      ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize
    );
    ImGui::Text("Test window \\o/");
    ImGui::Text("Mouse pos: %lf , %lf", mousePos.x, mousePos.y);
    ImGui::End();
  }

  void Update(IAppUtils& appUtils) override {
    if (appUtils.IsHold(Key::ESC)) {
      appUtils.Exit();
    }
    if (appUtils.IsPressed(Key::A)) {
      appUtils.SetMousePos({ 500.0, 500.0 });
    }

    mousePos = appUtils.GetMousePos();
  }

  void Render() override {
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0f, 0.0f, 0.0f); glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, 0.0f); glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f); glColor3f(0.0f, 0.0f, 1.0f);
    glEnd();
  }

private:
  glm::vec2 mousePos;
};

int main() {
  Application app;

  AppTest appTest;
  app.SetUiPresenter(&appTest);
  app.SetAppUpdater(&appTest);
  app.SetAppRenderer(&appTest);

  app.Run();

  return 0;
}