#include "GlfwContext.h"

int main() {
  GlfwContext context;
  context.Init(1280, 960, "Test");

  while (!context.ShouldClose()) {
    context.Swap();
    context.PoolEvents();
  }

  context.Cleanup();
  return 0;
}