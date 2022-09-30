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
    ImGui::End();
  }

  void Update(IAppUtils& appUtils) override {
    if (appUtils.IsHold(Key::ESC)) {
      appUtils.Exit();
    }
  }

  void Render() override {
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0f, 0.0f, 0.0f); glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, 0.0f); glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f); glColor3f(0.0f, 0.0f, 1.0f);
    glEnd();
  }
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