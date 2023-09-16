/*
-
  -
    -
  -
-
Uria - 2023

Thomas ROUSTAN
-
  -
    -
  -
-
*/

#include "Keys.hpp"

char *eventToChar(Keys::Key key) {
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