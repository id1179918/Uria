#ifndef INTERFACE_TOOL_HPP_
#define INTERFACE_TOOL_HPP_

#include "../core/Core.hpp"

class Core;
class Tool;

class InterfaceTool {
    public:
        InterfaceTool();
        ~InterfaceTool();

        virtual int handleInputs(Keys::Key);
        int update(Keys::Key) = 0;
        int render(WINDOW *) = 0;
    private:
        Tool *_currentTool;
        bool _toogleMenu;
};

#endif