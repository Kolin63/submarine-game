#ifndef CAMPFIRE_ENEMY_H
#define CAMPFIRE_ENEMY_H

#include <stdbool.h>

#include "pos.h"
#include "tile.h"

#define MAX_ENEMIES 10
#define ENEMY_RADIUS 8.0f

struct enemy {
  struct pos_float pos;
  bool active;
};

void enemies_init(struct enemy enemies[MAX_ENEMIES]);
void enemies_spawn(struct enemy enemies[MAX_ENEMIES], const struct tilemap* tm);

#endif
