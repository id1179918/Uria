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
    this->_toolInterface = new InterfaceTool();
    return (0);
}

Keys::Key Core::getInput()
{
    int key = wgetch(this->_window);

    switch (key) {
        case 'a':
            return (Keys::K_A);
        case 'b':
            return (Keys::K_B);
        case 'c':
            return (Keys::K_C);
        case 'd':
            return (Keys::K_D);
        case 'e':
            return (Keys::K_E);
        case 'f':
            return (Keys::K_F);
        case 'g':
            return (Keys::K_G);
        case 'h':
            return (Keys::K_H);
        case 'i':
            return (Keys::K_I);
        case 'j':
            return (Keys::K_J);
        case 'k':
            return (Keys::K_K);
        case 'l':
            return (Keys::K_L);
        case 'm':
            return (Keys::K_M);
        case 'n':
            return (Keys::K_N);
        case 'o':
            return (Keys::K_O);
        case 'p':
            return (Keys::K_P);
        case 'q':
            return (Keys::K_Q);
        case 'r':
            return (Keys::K_R);
        case 's':
            return (Keys::K_S);
        case 't':
            return (Keys::K_T);
        case 'u':
            return (Keys::K_U);
        case 'v':
            return (Keys::K_V);
        case 'w':
            return (Keys::K_W);
        case 'x':
            return (Keys::K_X);
        case 'y':
            return (Keys::K_Y);
        case 'z':
            return (Keys::K_Z);
        case KEY_UP:
            return (Keys::K_UP);
        case KEY_DOWN:
            return (Keys::K_DOWN);
        case KEY_LEFT:
            return (Keys::K_LEFT);
        case KEY_RIGHT:
            return (Keys::K_RIGHT);
        case 0x1B:
            return (Keys::K_EXIT);
        case ' ':
            return (Keys::K_SPACE);
        case KEY_BACKSPACE:
            return (Keys::K_BACKSPACE);
        case '\n':
            return (Keys::K_RETURN);
        case KEY_BTAB:
            return (Keys::K_CONTROL);
        default:
            return (Keys::K_UNDEFINED);
    }
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
	delwin(this->_window);
	endwin();
    delete this->_toolInterface;
    refresh();
}