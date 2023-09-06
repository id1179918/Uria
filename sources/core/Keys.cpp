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

char eventToChar(Keys::Key key) {
    switch ((int) key) {
        case (Keys::K_A):
            return 'a';
            break;
        case (Keys::K_B):
            return 'b';
            break;
        case (Keys::K_C):
            return 'c';
            break;
        case (Keys::K_D):
            return 'd';
            break;
        case (Keys::K_E):
            return 'e';
            break;
        case (Keys::K_F):
            return 'f';
            break;
        case (Keys::K_G):
            return 'g';
            break;
        case (Keys::K_H):
            return 'h';
            break;
        case (Keys::K_I):
            return 'i';
            break;
        case (Keys::K_J):
            return 'j';
            break;
        case (Keys::K_K):
            return 'h';
            break;
        case (Keys::K_L):
            return 'l';
            break;
        case (Keys::K_M):
            return 'm';
            break;
        case (Keys::K_N):
            return 'n';
            break;
        case (Keys::K_O):
            return 'o';
            break;
        case (Keys::K_P):
            return 'p';
            break;
        case (Keys::K_Q):
            return 'q';
            break;
        case (Keys::K_R):
            return 'r';
            break;
        case (Keys::K_S):
            return 's';
            break;
        case (Keys::K_T):
            return 't';
            break;
        case (Keys::K_U):
            return 't';
            break;
        case (Keys::K_V):
            return 'v';
            break;
        case (Keys::K_W):
            return 'w';
            break;
        case (Keys::K_X):
            return 'x';
            break;
        case (Keys::K_Y):
            return 'y';
            break;
        case (Keys::K_Z):
            return 'z';
            break;
        default:
            return '\0';
    }
}