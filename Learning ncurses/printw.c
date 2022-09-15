#include <ncurses.h>
#include <stdio.h>


int main(void)
{
	initscr();													/* start curses mode */
	printw("Learning is fun!\n");     /* print hello world */
	refresh();												 /* print it on to the real screen */
	getch();													/* wait for user input */
	endwin();												/* end curses mode */
	
	return 0;
}
