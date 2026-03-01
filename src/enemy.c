#include "enemy.h"

#include <stdlib.h>

#include "tile.h"

void enemies_init(struct enemy enemies[MAX_ENEMIES]) {
  for (int i = 0; i < MAX_ENEMIES; i++) {
    enemies[i].active = false;
  }
}

void enemies_spawn(struct enemy enemies[MAX_ENEMIES],
                   const struct tilemap* tm) {
  for (int i = 0; i < MAX_ENEMIES; i++) {
    if (!enemies[i].active) {
      int attempts = 0;
      while (attempts < 100) {
        int tx = rand() % MAP_WIDTH;
        int ty = rand() % MAP_HEIGHT;

        if (tx == 4 && ty == 2) {
          attempts++;
          continue;
        }

        if (isWalkable(tm, tx, ty)) {
          enemies[i].pos.x = (float)(tx * TILE_SIZE);
          enemies[i].pos.y = (float)(ty * TILE_SIZE);
          enemies[i].active = true;
          break;
        }
        attempts++;
      }
    }
  }
}
