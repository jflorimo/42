#include <ncurses.h>

int main()
{
	initscr();
	keypad(stdscr, true);
	printw("UP: %i ", has_key(KEY_UP));
	mvprintw(1, 0, "DOWN: %i ", has_key(KEY_DOWN));
	mvprintw(2, 0, "LEFT: %i", has_key(KEY_LEFT));
	mvprintw(3, 0, "RIGHT: %i", has_key(KEY_RIGHT));
	getch();
	endwin();
	return 0;
}
