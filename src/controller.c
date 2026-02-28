#include "controller.h"

#include <raylib.h>

#include "manager.h"

void controller_tick() {
  if (IsKeyPressed(KEY_ESCAPE)) {
    manager_get_global()->game_should_run = false;
  }
}
