#ifndef TOOL_HPP_
#define TOOL_HPP_

#include <iostream>

#include "Core.hpp"
#include "InterfaceTool.hpp"

class Tool {
    public:
        Tool(const char *);
        ~Tool();
        bool getToggle();
        const char *getName();
    private:
        const char *_name;
        bool _toggle;
        //time_since_last_use
};

#endif