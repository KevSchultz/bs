/* Created by Kevin Schultz */
/* Inspired by sl.          */

#include <ncurses.h>
#include <unistd.h>

#define SLUG1STR1 "o     o\n"
#define SLUG1STR2 " \\   /      __________\n"
#define SLUG1STR3 "  \\__\\_____/          \\________\n"
#define SLUG1STR4 "  /           _________        \\\n"
#define SLUG1STR5 "  \\_________/          \\________)\n"

#define SLUG2STR1 "o     o\n"
#define SLUG2STR2 " \\   /\n"
#define SLUG2STR3 "  \\__\\___________________________\n"
#define SLUG2STR4 "  /                              \\\n"
#define SLUG2STR5 "  \\_______________________________)\n"

/* Prints the first frame of the slug */
/* with printw.                       */
void slug1_print(int x, int y) {
  mvprintw(y, x, SLUG1STR1);
  mvprintw(y + 1, x, SLUG1STR2);
  mvprintw(y + 2, x, SLUG1STR3);
  mvprintw(y + 3, x, SLUG1STR4);
  mvprintw(y + 4, x, SLUG1STR5);
}

/* Prints the first frame of the slug */
/* with printw.                       */
void slug2_print(int x, int y) {
  mvprintw(y, x, SLUG2STR1);
  mvprintw(y + 1, x, SLUG2STR2);
  mvprintw(y + 2, x, SLUG2STR3);
  mvprintw(y + 3, x, SLUG2STR4);
  mvprintw(y + 4, x, SLUG2STR5);
}

int main(void) {

  // Setup ncurses window
  initscr();
  raw();
  noecho();
  curs_set(0);
  leaveok(stdscr, TRUE);
  leaveok(stdscr, TRUE);
  scrollok(stdscr, FALSE);

  // Color the slug yellow.
  start_color();
  init_pair(1, COLOR_YELLOW, COLOR_BLACK);
  attron(COLOR_PAIR(1));

  int frame = 1;

  for (int x = COLS - 36; x >= 0; x--) {

    if (frame == 1) {
      slug1_print(x, LINES / 2);
    } else {
      slug2_print(x, LINES / 2);
    }

    if (x % 5 == 0) {
      frame = (frame == 1) ? 2 : 1;
    }

    refresh();
    usleep(100000);
  }

  attroff(COLOR_PAIR(1));
  mvcur(0, COLS - 1, LINES - 1, 0);
  endwin();

  return 0;
}
