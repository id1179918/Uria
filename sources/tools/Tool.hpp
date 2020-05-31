#ifndef TOOL_HPP_
#define TOOL_HPP_

#include <iostream>

#include "Core.hpp"
#include "InterfaceTool.hpp"

class Tool : public InterfaceTool {
    public:
        Tool();
        ~Tool();
        int render(WINDOW *);
    private:
        WINDOW *_subWindow;
        std::string _name;
        bool _toggle;
};

#endif