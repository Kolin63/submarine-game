#include <raylib.h>
#include <stdlib.h>

#include "manager.h"

int main() {
  manager_init();
  atexit(manager_cleanup);
  manager_run_game();
  manager_cleanup();

  return 0;
}
