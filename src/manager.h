#ifndef CAMPFIRE_MANAGER_H
#define CAMPFIRE_MANAGER_H

#include "player.h"

struct manager {
  struct player* player;
};

void manager_init();
void manager_cleanup();

struct manager* manager_get_global();

#endif
