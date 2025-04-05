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

#include "Core.hpp"
#include "InterfaceTool.hpp"
#include "../errors/Errors.hpp"

int Core::init()
{
    int exitCode = this->_graphics->init();

    //this->_toolInterface = new InterfaceTool(_window, COLS, LINES);
    return (exitCode);
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
    int exitCode = EX_OK;
    //Keys::Key event;

    //this->_toolInterface->initCoods();

    while (this->_isRunning) {
        //event = this->_eventHandler->getInput();
        //if (event == Keys::K_EXIT) {
        //    // save instance
        //    //this->getTools()->fileManager()->save(
        //    //    this->getTools()->getCurrentTool()->getBuffer(),
        //    //    this->getTools()->getCurrentTool()->getName()
        //    //);
        //    this->setIsRunning(false);
        //}
        if (!this->_isRunning) {
            exitCode = EX_ESCAPE;
            break;
        }
        //wrefresh(this->_window);
        ////out << (int)event << std::endl;
        //// Ncurses Graphics
        //exitCode = this->getTools()->update(event);
        exitCode = this->_graphics->render();

    }
    return (exitCode);
}

Core::Core()
{
    //this->_height = LINES;
    //this->_width = COLS;
    //this->_row = 0;
    //this->_col = 0;
    this->_window = newwin(0, 0, 0, 0);
    this->_graphics = new Graphics();
    this->_graphics->setWindow(this->_window);
    this->_eventHandler = new EventHandler(this->_window);
    this->_isRunning = true;
    refresh();
}

Core::~Core()
{
    delete this->_toolInterface;
}