/*
-
  -
    -
  -
-
Uria - 2021

Thomas ROUSTAN
-
  -
    -
  -
-
*/

#include "Ncurses.hpp"
#include "Coords.hpp"

//typedef struct screenCoords_t;

//void resizableScreen()
//{
//	size_t tmp[2] = {0, 0};
//	size_t max[2] = {0, 0};
//	std::string str1 = " Please increase the window size or press Q or ESCAPE to close the program.  ";
//
//	getmaxyx(stdscr, max[0], max[1]);
//	if (max[0] < 55 || max[1] < 211) {
//		while (max[0] < 55 && max[1] < 211) {
//			getmaxyx(stdscr, max[0], max[1]);
//			if (tmp[0] != max[0] || tmp[1] != max[1]) {
//				tmp[0] = max[0];
//				tmp[1] = max[1];
//				this->clear();
//				move(LINES / 2, (COLS / 2) - (str1.size() / 2));
//				printw(str1.c_str());
//			}
//			refresh();
//		}
//		this->clear();
//		refresh();
//	}
//}

//void writeTextBuffer(std::string buffer)
//{
//  return;
//}
//
//void paintTextBuffer(std::string buffer, int x, int y)
//{
//  return;
//}

int Graphics::render()
{
    std::string buffer_col = std::to_string(_col);
    std::string buffer_row = std::to_string(_row);

    wclear(_window);
    //rectangle(0, 0, (COLS - 1), (LINES - 1), _window);
    wattron(_window, COLOR_PAIR(3));
    printw(buffer_col.c_str());
    printDebug(buffer_col.c_str());
    wattroff(_window, COLOR_PAIR(3));
    wrefresh(_window);
    return (EX_OK);
};

void Graphics::printDebug(const char *str)
{
    mvwprintw(_window, 1, 1, str);
    return;
}


int Graphics::getRow()
{
    return this->_row;
}

int Graphics::getCol()
{
    return this->_col;
}

void Graphics::initTerminal()
{
    initscr();
	  cbreak();
	  noecho();
	  nodelay(stdscr, true);
	  keypad(stdscr, true);
    getmaxyx(stdscr, this->_row, this->_col);
	  curs_set(0);
	  timeout(0);
    return;

}

void Graphics::initColor()
{
    start_color();

    //Police color
	  init_pair(0, COLOR_BLACK, COLOR_BLACK);
	  init_pair(1, COLOR_RED, COLOR_BLACK);
	  init_pair(2, COLOR_GREEN, COLOR_BLACK);
	  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	  init_pair(4, COLOR_BLUE, COLOR_BLACK);
	  init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	  init_pair(6, COLOR_CYAN, COLOR_BLACK);
	  init_pair(7, COLOR_WHITE, COLOR_BLACK);

    //Full cursor box color
	  init_pair(8, COLOR_RED, COLOR_RED);
	  init_pair(9, COLOR_GREEN, COLOR_GREEN);
	  init_pair(10, COLOR_YELLOW, COLOR_YELLOW);
	  init_pair(11, COLOR_BLUE, COLOR_BLUE);
	  init_pair(12, COLOR_MAGENTA, COLOR_MAGENTA);
	  init_pair(13, COLOR_CYAN, COLOR_CYAN);
	  init_pair(14, COLOR_WHITE, COLOR_WHITE);

    //Black police
    init_pair(15, COLOR_BLACK, COLOR_GREEN);

    init_pair(16, COLOR_MAGENTA, COLOR_CYAN);

    init_pair(17, COLOR_BLACK, COLOR_WHITE);

    init_color(COLOR_BLACK, 0, 0, 0);
    return;
}

void Graphics::rectangle(int x1, int y1, int x2, int y2, WINDOW *_window)
{
    mvwhline(_window, y1, x1, 0, x2-x1);
    mvwhline(_window, y2, x1, 0, x2-x1);
    mvwvline(_window, y1, x1, 0, y2-y1);
    mvwvline(_window, y1, x2, 0, y2-y1);
    mvwaddch(_window, y1, x1, ACS_ULCORNER);
    mvwaddch(_window, y2, x1, ACS_LLCORNER);
    mvwaddch(_window, y1, x2, ACS_URCORNER);
    mvwaddch(_window, y2, x2, ACS_LRCORNER);
    return;
}

void Graphics::setWindow(WINDOW *win)
{
    this->_window = win;
    return;
}

WINDOW *Graphics::getWindow()
{
    return (this->_window);
}
int Graphics::init()
{
    initTerminal();
    if (has_colors() == false) {
        endwin();
        std::cerr << "Your terminal does not support colors" << std::endl;
        return (EX_NCURSES);
    }
	  initColor();
    return (EX_OK);
}

Graphics::Graphics()
{
    this->_window = newwin(LINES, COLS, 0, 0);
}

Graphics::~Graphics()
{
  	werase(this->_window);
    wrefresh(this->_window);
	  delwin(this->_window);
	  endwin();
    refresh();
}