#ifndef CAMPFIRE_MANAGER_H
#define CAMPFIRE_MANAGER_H

#include "player.h"

struct manager {
  bool game_should_run;
  struct player* player;
};

void manager_init();
void manager_cleanup();

void manager_run_game();

struct manager* manager_get_global();

#endif
