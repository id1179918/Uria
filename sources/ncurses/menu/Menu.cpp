#include "Core.hpp"
#include "Ncurses.hpp"

void displayMenuTyping(WINDOW *_window)
{
    rectangle(1, 1, (COLS - COLS + 14), (LINES - 2), _window);
    wattron(_window, COLOR_PAIR(2));
    mvwprintw(_window, (LINES - LINES) + 2, (COLS - COLS) + 6, "MENU");
    wattroff(_window, COLOR_PAIR(2));
    mvwprintw(_window, (LINES - LINES) + 6, (COLS - COLS) + 5, "NOTEPAD");
    mvwprintw(_window, (LINES - LINES) + 8, (COLS - COLS) + 4, "REMINDER");
    mvwprintw(_window, (LINES - LINES) + 10, (COLS - COLS) + 4, "CALENDAR");
    return;
}

void displayMenuNav(WINDOW *_window)
{
    wattron(_window, COLOR_PAIR(3));
    rectangle(1, 1, (COLS - COLS + 14), (LINES - 2), _window);
    wattroff(_window, COLOR_PAIR(3));
    wattron(_window, COLOR_PAIR(2));
    mvwprintw(_window, (LINES - LINES) + 2, (COLS - COLS) + 6, "MENU");
    wattroff(_window, COLOR_PAIR(2));
    //for ()
    mvwprintw(_window, (LINES - LINES) + 6, (COLS - COLS) + 4, "NOTEPAD");
    mvwprintw(_window, (LINES - LINES) + 8, (COLS - COLS) + 4, "REMINDER");
    mvwprintw(_window, (LINES - LINES) + 10, (COLS - COLS) + 4, "CALENDAR");
    return;
}