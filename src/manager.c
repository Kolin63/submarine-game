#include "manager.h"

#include <raylib.h>
#include <stdlib.h>

#include "controller.h"
#include "player.h"
#include "render.h"

static struct manager* global_manager;

void manager_init() {
  global_manager = malloc(sizeof(struct manager));
  global_manager->player = malloc(sizeof(struct player));
  global_manager->player->pos.x = 0;
  global_manager->player->pos.y = 0;

  InitWindow(400, 300, "Submarine Game");

  global_manager->game_should_run = true;
}

void manager_cleanup() {
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
