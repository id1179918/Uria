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

#include "Core.hpp"
#include "InterfaceTool.hpp"
#include "../errors/Errors.hpp"

void Core::setWindow(WINDOW *win)
{
    this->_window = win;
    return;
}

WINDOW *Core::getWindow()
{
    return (this->_window);
}

void Core::initTerminal()
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

void Core::initColor()
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

    init_color(COLOR_BLACK, 0, 0, 0);
    return;
}

int Core::init()
{
    initTerminal();
    if (has_colors() == false) {
        endwin();
        std::cerr << "Your terminal does not support colors" << std::endl;
        return (84);
    }
	initColor();
    this->_window = newwin(LINES, COLS, 0, 0);
    this->_toolInterface = new InterfaceTool(_window);
    return (0);
}

Keys::Key Core::getInput()
{
    int key = wgetch(this->_window);

    switch (key) {
        case 'a':
            return (Keys::K_A);
            break;
        case 'b':
            return (Keys::K_B);
            break;
        case 'c':
            return (Keys::K_C);
            break;
        case 'd':
            return (Keys::K_D);
            break;
        case 'e':
            return (Keys::K_E);
            break;
        case 'f':
            return (Keys::K_F);
            break;
        case 'g':
            return (Keys::K_G);
            break;
        case 'h':
            return (Keys::K_H);
            break;
        case 'i':
            return (Keys::K_I);
            break;
        case 'j':
            return (Keys::K_J);
            break;
        case 'k':
            return (Keys::K_K);
            break;
        case 'l':
            return (Keys::K_L);
            break;
        case 'm':
            return (Keys::K_M);
            break;
        case 'n':
            return (Keys::K_N);
            break;
        case 'o':
            return (Keys::K_O);
            break;
        case 'p':
            return (Keys::K_P);
            break;
        case 'q':
            return (Keys::K_Q);
            break;
        case 'r':
            return (Keys::K_R);
            break;
        case 's':
            return (Keys::K_S);
            break;
        case 't':
            return (Keys::K_T);
            break;
        case 'u':
            return (Keys::K_U);
            break;
        case 'v':
            return (Keys::K_V);
            break;
        case 'w':
            return (Keys::K_W);
            break;
        case 'x':
            return (Keys::K_X);
            break;
        case 'y':
            return (Keys::K_Y);
            break;
        case 'z':
            return (Keys::K_Z);
            break;
        case '\033':
            wgetch(this->_window);
            switch (wgetch(this->_window)) {
                case '3':
                    switch (wgetch(this->_window)) {
                        case '~':
                            return (Keys::K_CLOSE);
                            break;
                    }
                    break;
                case 'A':
                    return (Keys::K_UP);
                    break;
                case 'B':
                    return (Keys::K_DOWN);
                    break;
                case 'C':
                    return (Keys::K_RIGHT);
                    break;
                case 'D':
                    return (Keys::K_LEFT);
                    break;
                default:
                    return (Keys::K_EXIT);
                    break;

            }
            break;
        case ' ':
            return (Keys::K_SPACE);
            break;
        case KEY_BACKSPACE:
            return (Keys::K_BACKSPACE);
            break;
        case '\n':
            return (Keys::K_RETURN);
            break;
        case KEY_BTAB:
        case '\t':
            return (Keys::K_CONTROL);
            break;
        default:
            return (Keys::K_UNDEFINED);
            break;
    }
    return (Keys::K_UNDEFINED);
}

InterfaceTool *Core::getTools(void)
{
    return (this->_toolInterface);
}

void Core::setIsRunning(bool state)
{
    this->_isRunning = state;
    return;
}

int Core::run()
{
    int exitCode = 0;
    Keys::Key event;

    while (this->_isRunning) {
        event = this->getInput();
        if (event == Keys::K_EXIT) {
            // save instance
            this->setIsRunning(false);
        }
        wrefresh(this->_window);
        //out << (int)event << std::endl;
        // Ncurses Graphics
        exitCode = this->getTools()->update(event);
        exitCode = this->getTools()->render(this->_window);
    }
    return (exitCode);
}

Core::Core()
{
    this->_height = LINES;
    this->_width = COLS;
    this->_row = 0;
    this->_col = 0;
    this->_isRunning = true;
    refresh();
}

Core::~Core()
{
	werase(this->_window);
    wrefresh(this->_window);
	delwin(this->_window);
	endwin();
    delete this->_toolInterface;
    refresh();
}