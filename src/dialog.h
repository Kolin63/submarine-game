#ifndef CAMPFIRE_DIALOG_H
#define CAMPFIRE_DIALOG_H

#include <raylib.h>
#include <stdbool.h>

#define MAX_DIALOG_LINES 16
#define MAX_LINE_LENGTH 256
#define DIALOG_TYPING_SPEED 30.0f
#define DIALOG_BOX_HEIGHT 160
#define DIALOG_PADDING 20

struct dialog_box {
  const char* lines[MAX_DIALOG_LINES];
  int line_count;
  int current_line;
  bool active;
  const char* speaker;
  float characters_shown;
  Font font;
};

void dialog_init(struct dialog_box* db);
void dialog_show(struct dialog_box* db, const char* speaker, const char** lines,
                 int count);
void dialog_update(struct dialog_box* db, float dt);
void dialog_advance(struct dialog_box* db);
void dialog_draw(const struct dialog_box* db);

#endif
