#include <lib/scanf.h>
#include <lib/echo.h>

#define CMD_ECHO 0x0

int (*built_in_cmds[])() = {
  echo
};

int find_and_run_built_in_cmd(char *cmd_name) {
  // TODO strcmpで比較する
  // TODO x, xpコマンドを実装する
  if (cmd_name == "echo") {built_in_cmds[CMD_ECHO]();return 0;}
  return -1;
}

void shell_main() {
  char cmd[256];
  int ret;

  /* main loop */
  while (1) {
    memset(cmd, NULL, sizeof(cmd));

    /* prompt */
    echo("mutex-os > ");
    scanf(cmd);

    // TODO spaceを実装する
    // TODO backspaceを実装する
    // TODO cmdをsplitする
    ret = find_and_run_built_in_cmd(cmd);

    /* TODO search filesystem */

    if (ret != 0) {echo("command not found:");echo(cmd);}

    echo("\n");
  }
}
