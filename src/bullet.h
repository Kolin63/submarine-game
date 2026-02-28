#ifndef CAMPFIRE_BULLET_H
#define CAMPFIRE_BULLET_H

#include <raylib.h>
#include <stdbool.h>

#define MAX_BULLETS 100
#define BULLET_SPEED 600.0f
#define BULLET_RADIUS 4.0f

struct bullet {
  Vector2 pos;
  Vector2 velocity;
  bool active;
};

void bullet(struct bullet* b);
void bullet_fire(struct bullet* b, Vector2 pos, Vector2 direction);
void bullet_update(struct bullet* b, float dt);
void bullet_draw(const struct bullet* b);

#endif
