#include "controller.h"

#include <raylib.h>

#include "dialog.h"
#include "manager.h"
#include "tile.h"

#define PLAYER_SPEED 1

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

  struct player* player = manager_get_global()->player;

  const bool up = IsKeyDown(KEY_W);
  const bool left = IsKeyDown(KEY_A);
  const bool down = IsKeyDown(KEY_S);
  const bool right = IsKeyDown(KEY_D);

  const float velocity_x = right * PLAYER_SPEED - left * PLAYER_SPEED;
  const float velocity_y = down * PLAYER_SPEED - up * PLAYER_SPEED;

  player->pos.x += velocity_x;
  player->pos.y += velocity_y;
}
