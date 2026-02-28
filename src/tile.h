#ifndef CAMPFIRE_TILE_H
#define CAMPFIRE_TILE_H

#include <raylib.h>

#define TILE_SIZE 32
#define MAP_WIDTH 25
#define MAP_HEIGHT 19

typedef enum { TILE_ROCK, TILE_WATER, TILE_COUNT } TileType;

struct tilemap {
  TileType tiles[MAP_HEIGHT][MAP_WIDTH];
};

void tilemap_init(struct tilemap* tm);
void tilemap_draw(const struct tilemap* tm);
Color tilemap_get_color(TileType type);

#endif
