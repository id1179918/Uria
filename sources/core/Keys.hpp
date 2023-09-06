#ifndef KEYS_HPP_
#define KEYS_HPP_

namespace Keys {
    enum Key {
        K_A,
        K_B,
        K_C,
        K_D,
    	K_E,
        K_F,
        K_G,
        K_H,
        K_I,
        K_J,
        K_K,
        K_L,
        K_M,
    	K_N,
    	K_O,
        K_P,
        K_Q,
        K_R,
    	K_S,
        K_T,
        K_U,
        K_V,
        K_W,
        K_X,
        K_Y,
        K_Z,
    	K_UP,
    	K_DOWN,
    	K_LEFT,
    	K_RIGHT,
    	K_SPACE,
        K_RETURN,
        K_BACKSPACE,
        K_EXIT,
    	K_UNDEFINED,
        K_CONTROL,
        K_CLOSE
    };
};

char eventToChar(Keys::Key);

#endif