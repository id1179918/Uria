#include "Ncurses.hpp"

void Ncurses::resizableScreen() {
	size_t tmp[2] = {0, 0};
	size_t max[2] = {0, 0};
	std::string str1 = " Please increase the window size or press Q or ESCAPE to close the program.  ";

	getmaxyx(stdscr, max[0], max[1]);
	if (max[0] < 55 || max[1] < 211) {
		while (max[0] < 55 && max[1] < 211) {
			getmaxyx(stdscr, max[0], max[1]);
			if (tmp[0] != max[0] || tmp[1] != max[1]) {
				tmp[0] = max[0];
				tmp[1] = max[1];
				this->clear();
				move(LINES / 2, (COLS / 2) - (str1.size() / 2));
				printw(str1.c_str());
			}
			refresh();
		}
		this->clear();
		refresh();
	}
}