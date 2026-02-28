#ifndef CAMPFIRE_MANAGER_H
#define CAMPFIRE_MANAGER_H

#include "player.h"
#include "tile.h"

struct manager {
  struct player* player;
  struct tilemap* tilemap;
};

void manager_init();
void manager_update();
void manager_draw();
void manager_cleanup();

struct manager* manager_get_global();

#endif
