#include "controller.h"

#include <raylib.h>

#include "dialog.h"
#include "manager.h"
#include "tile.h"

void controller_tick() {
  struct manager* mgr = manager_get_global();

  if (IsKeyPressed(KEY_ESCAPE) || WindowShouldClose()) {
    mgr->game_should_run = false;
    return;
  }

  if (mgr->dialog->active) {
    if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)) {
      dialog_advance(mgr->dialog);
    }
    return;
  }

  struct player* p = mgr->player;
  const struct tilemap* tm = mgr->tilemap;

  int tx = (int)p->pos.x;
  int ty = (int)p->pos.y;

  if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
    if (isWalkable(tm, tx, ty - 1)) {
      p->pos.y = (float)(ty - 1);
    }
  }
  if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) {
    if (isWalkable(tm, tx, ty + 1)) {
      p->pos.y = (float)(ty + 1);
    }
  }
  if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
    if (isWalkable(tm, tx - 1, ty)) {
      p->pos.x = (float)(tx - 1);
    }
  }
  if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
    if (isWalkable(tm, tx + 1, ty)) {
      p->pos.x = (float)(tx + 1);
    }
  }
}
