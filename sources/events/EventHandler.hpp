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

#ifndef EVENT_HANDLER_HPP_
#define EVENT_HANDLER_HPP_

#include "Keys.hpp"

class EventHandler {
    public:
        EventHandler(WINDOW *);
        ~EventHandler();

        char *eventToChar(Keys::Key);
        Keys::Key getInput();
    private:
        WINDOW *_window;
};

#endif