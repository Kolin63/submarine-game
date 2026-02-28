#include "dialog.h"

#include <string.h>

void dialog_init(struct dialog_box* db) {
  db->line_count = 0;
  db->current_line = 0;
  db->active = false;
  db->speaker = NULL;
  db->characters_shown = 0;
  db->font = GetFontDefault();
}

void dialog_show(struct dialog_box* db, const char* speaker, const char** lines,
                 int count) {
  db->speaker = speaker;
  db->line_count = (count < MAX_DIALOG_LINES) ? count : MAX_DIALOG_LINES;
  for (int i = 0; i < db->line_count; i++) {
    db->lines[i] = lines[i];
  }
  db->current_line = 0;
  db->active = true;
  db->characters_shown = 0;
}

void dialog_update(struct dialog_box* db, float dt) {
  if (!db->active) return;

  int total_chars = strlen(db->lines[db->current_line]);
  if (db->characters_shown < (float)total_chars) {
    db->characters_shown += DIALOG_TYPING_SPEED * dt;
    if (db->characters_shown > (float)total_chars) {
      db->characters_shown = (float)total_chars;
    }
  }
}

void dialog_advance(struct dialog_box* db) {
  if (!db->active) return;

  int total_chars = strlen(db->lines[db->current_line]);

  if (db->characters_shown < (float)total_chars) {
    db->characters_shown = (float)total_chars;
    return;
  }
  db->current_line++;
  db->characters_shown = 0;

  if (db->current_line >= db->line_count) {
    db->active = false;
  }
}

void dialog_draw(const struct dialog_box* db) {
  if (!db->active) return;

  int screenWidth = GetScreenWidth();
  int screenHeight = GetScreenHeight();

  int x = DIALOG_PADDING;
  int y = screenHeight - DIALOG_BOX_HEIGHT - DIALOG_PADDING;
  int width = screenWidth - 2 * DIALOG_PADDING;
  int height = DIALOG_BOX_HEIGHT;

  DrawRectangle(x, y, width, height, Fade(BLACK, 0.8f));
  DrawRectangleLines(x, y, width, height, WHITE);

  if (db->speaker) {
    DrawTextEx(db->font, db->speaker, (Vector2){(float)x + 15, (float)y + 10},
               30, 2, YELLOW);
  }

  const char* full_text = db->lines[db->current_line];
  int chars_to_show = (int)db->characters_shown;

  DrawTextEx(db->font, TextSubtext(full_text, 0, chars_to_show),
             (Vector2){(float)x + 20, (float)y + 50}, 24, 1, WHITE);

  if (chars_to_show >= (int)strlen(full_text)) {
    const char* prompt = (db->current_line < db->line_count - 1)
                             ? "Press SPACE to continue"
                             : "Press SPACE to close";
    int promptWidth = MeasureTextEx(db->font, prompt, 18, 1).x;
    DrawTextEx(
        db->font, prompt,
        (Vector2){(float)x + width - promptWidth - 15, (float)y + height - 30},
        18, 1, GRAY);
  }
}
