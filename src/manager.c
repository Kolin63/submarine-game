#include "manager.h"

#include <raylib.h>
#include <stdlib.h>

#include "controller.h"
#include "player.h"
#include "render.h"
#include "tile.h"


static struct manager* global_manager;

void manager_init() {
  global_manager = malloc(sizeof(struct manager));
  global_manager->player = malloc(sizeof(struct player));
  global_manager->player->pos.x = 0;
  global_manager->player->pos.y = 0;

  global_manager->tilemap = malloc(sizeof(struct tilemap));
  tilemap_init(global_manager->tilemap);

  InitWindow(MAP_WIDTH * TILE_SIZE, MAP_HEIGHT * TILE_SIZE, "Submarine Game");
  SetTargetFPS(60);
}

void manager_draw() {
  BeginDrawing();
  ClearBackground(BLACK);

  tilemap_draw(global_manager->tilemap);

  DrawRectangle(global_manager->player->pos.x * TILE_SIZE + 4,
                global_manager->player->pos.y * TILE_SIZE + 4, TILE_SIZE - 8,
                TILE_SIZE - 8, YELLOW);

  EndDrawing();
}

void manager_cleanup() {
  CloseWindow();
  free(global_manager->tilemap);
  free(global_manager->player);
  free(global_manager);
}

void manager_run_game() {
  while (global_manager->game_should_run) {
    controller_tick();
    render_game();
  }
}

struct manager* manager_get_global() { return global_manager; }
