#include <ncurses.h>

WINDOW *createWindow( int height, int width )
{	
	WINDOW *window;

	initscr();
	cbreak();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	window = newwin(height, width, 0, 0);

	wrefresh(window);

	return window;
}

void refreshWindow( WINDOW* window )
{
	wrefresh(window);
}

void destroyWindow( WINDOW *window )
{
	delwin(window);
	endwin();
}

void clearWindow( WINDOW *window )
{
	// wclear(window); seems to be too slow
	clear();
}

int	getKeyPressed( void )
{
	return getch();
}

int main(int argc, char *argv[])
{	
	WINDOW *my_win;
	
	int ch;
	int x, y;
	
	x = 0;
	y = 0;

	my_win = createWindow(10, 20);
	refresh();
	while((ch = getKeyPressed()) != 27)
	{
		clearWindow(my_win);
		if (ch == KEY_DOWN)
			x++;
		else if (ch == KEY_UP)
			x--;
		else if (ch == KEY_LEFT)
			y--;
		else if (ch == KEY_RIGHT)
			y++;
		mvprintw(x, y, "yolooo");
		refreshWindow(my_win);
	}
		
	destroyWindow(my_win);
	return 0;
}
