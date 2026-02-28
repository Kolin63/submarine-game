#include <raylib.h>

#include "manager.h"

int main() {
  manager_init();

  while (!WindowShouldClose()) {
    manager_update();
    manager_draw();
  }

  manager_cleanup();

  return 0;
}
