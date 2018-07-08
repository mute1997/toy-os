#include <lib/scanf.h>
#include <lib/echo.h>
#include <mm.h>

typedef struct cmd {
  char *cmd_name;
  int (*built_in_cmds)(char*);
  struct cmd *next;
} cmd_t;

cmd_t first_built_in_cmd;

cmd_t *get_end_built_in_cmd() {
  struct cmd *p = &first_built_in_cmd;
  while (p->next != NULL) {
    p = p->next;
  }
  return p;
}

void define_cmd(char *cmd_name, int (*built_in_cmd)(char*)) {
  cmd_t *p = get_end_built_in_cmd();
  cmd_t *c = kmalloc(sizeof(cmd_t));
  memset(c, NULL, sizeof(c));
  c->cmd_name = cmd_name;
  c->built_in_cmds = built_in_cmd;
  p->next = c;
}

int find_and_run_built_in_cmd(char *cmd_name, char *arg) {
  struct cmd *p = &first_built_in_cmd;
  while (p->next != NULL) {
    p = p->next;
    p->cmd_name;
    if (strcmp(p->cmd_name) == 0) { // TODO ここでページフォルトが起きる
      p->built_in_cmds(arg);
      return 0;
    }
  }
  return -1;
}

void setup_built_in_cmds() {
// TODO exitコマンド
// TODO xコマンド
// TODO xpコマンド
  define_cmd("echo", echo);
}

// TODO コンテキストスイッチさせる
// TODO ユーザーランドで動作させる
void shell_main() {
  char cmd[256];
  int ret;

  /* reigister built-in commands */
  setup_built_in_cmds();

  /* main loop */
  while (1) {
    memset(cmd, NULL, sizeof(cmd));

    /* prompt */
    echo("mutex-os > ");
    scanf(cmd);

    // TODO cmdをsplitしてコマンド名と引数に分ける
    char *arg = "arg";
    ret = find_and_run_built_in_cmd(cmd, arg);

    if (ret != 0) {echo("command not found:");echo(cmd);}

    echo("\n");
  }
}
