#include "EventHandler.hpp"

EventHandler::EventHandler(WINDOW* window)
{
    this->_window = window;
}

EventHandler::~EventHandler()
{

}


Keys::Key EventHandler::getInput()
{
    int key = wgetch(_window);

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
            wgetch(_window);
            switch (wgetch(_window)) {
                case '3':
                    switch (wgetch(_window)) {
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

char *EventHandler::eventToChar(Keys::Key key) {
    switch ((int) key) {
        case (Keys::K_A):
            return strdup("a");
            break;
        case (Keys::K_B):
            return strdup("b");
            break;
        case (Keys::K_C):
            return strdup("c");
            break;
        case (Keys::K_D):
            return strdup("d");
            break;
        case (Keys::K_E):
            return strdup("e");
            break;
        case (Keys::K_F):
            return strdup("f");
            break;
        case (Keys::K_G):
            return strdup("g");
            break;
        case (Keys::K_H):
            return strdup("h");
            break;
        case (Keys::K_I):
            return strdup("i");
            break;
        case (Keys::K_J):
            return strdup("j");
            break;
        case (Keys::K_K):
            return strdup("h");
            break;
        case (Keys::K_L):
            return strdup("l");
            break;
        case (Keys::K_M):
            return strdup("m");
            break;
        case (Keys::K_N):
            return strdup("n");
            break;
        case (Keys::K_O):
            return strdup("o");
            break;
        case (Keys::K_P):
            return strdup("p");
            break;
        case (Keys::K_Q):
            return strdup("q");
            break;
        case (Keys::K_R):
            return strdup("r");
            break;
        case (Keys::K_S):
            return strdup("s");
            break;
        case (Keys::K_T):
            return strdup("t");
            break;
        case (Keys::K_U):
            return strdup("t");
            break;
        case (Keys::K_V):
            return strdup("v");
            break;
        case (Keys::K_W):
            return strdup("w");
            break;
        case (Keys::K_X):
            return strdup("x");
            break;
        case (Keys::K_Y):
            return strdup("y");
            break;
        case (Keys::K_Z):
            return strdup("z");
            break;
        case (Keys::K_SPACE):
            return strdup(" ");
            break;
    }
    return strdup(" ");
}
