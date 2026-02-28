#include "manager.h"

#include <raylib.h>
#include <stdlib.h>

#include "player.h"

static struct manager* global_manager;

void manager_init() {
  global_manager = malloc(sizeof(struct manager));
  global_manager->player = malloc(sizeof(struct player));
  global_manager->player->pos.x = 0;
  global_manager->player->pos.y = 0;

  InitWindow(400, 300, "Submarine Game");
}

void manager_cleanup() {
  free(global_manager->player);
  free(global_manager);
}

struct manager* manager_get_global() {
  return global_manager;
}
