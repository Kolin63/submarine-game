#include "render.h"

#include <raylib.h>

#include "manager.h"
#include "tile.h"

// forward declarations
void render_tiles();
void render_player();
void render_dialog();

void render_game() {
  BeginDrawing();

  ClearBackground(BLACK);

  render_tiles();
  render_player();
  render_dialog();

  EndDrawing();
}

void render_tiles() {
  tilemap_draw(manager_get_global()->tilemap);
}

void render_player() {
  const struct player* player = manager_get_global()->player;
  DrawRectangle(player->pos.x, player->pos.y, 20, 20, WHITE);
}

void render_dialog() {
  dialog_draw(manager_get_global()->dialog);
}
