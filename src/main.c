#include <raylib.h>

#include "manager.h"

int main() {
  manager_init();
  manager_run_game();
  manager_cleanup();

  return 0;
}
