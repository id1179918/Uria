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

#include "InterfaceTool.hpp"
#include "Tool.hpp"
#include "Core.hpp"
#include "Ncurses.hpp"
#include "Menu.hpp"

void InterfaceTool::displayToolsWithMenuNav(WINDOW *_window)
{
    try {
        for (int it = 0; it != (int) this->_tools.size(); it++) {
            if (this->_tools[it]->getToggle() == true) {
                //mvwprintw(_window, 7, 100, this->_tools[it]->getName());
                if (this->_tools[it] == this->_currentTool) {
                    switch ((int) this->_screenSetup) {
                        case InterfaceTool::ScreenSetup::NONE:
                            break;
                        case InterfaceTool::ScreenSetup::WIDE:
                            wattron(_window, COLOR_PAIR(3));
                            rectangle((COLS - COLS + 15), 1, (COLS - 2), (LINES - 2), _window);
                            wattroff(_window, COLOR_PAIR(3));
                            break;
                    }
                } else {
                    switch ((int) this->_screenSetup) {
                        case InterfaceTool::ScreenSetup::NONE:
                            break;
                        case InterfaceTool::ScreenSetup::WIDE:
                            rectangle((COLS - COLS + 15), 1, (COLS - 2), (LINES - 2), _window);
                            break;
                    }
                }
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Uria error from InterfaceTool displaying module: " << e.what() << std::endl;
    }
    return;
}

void InterfaceTool::displayToolsWithMenuTyp(WINDOW *_window)
{
    try {
        for (int it = 0; it != (int) this->_tools.size(); it++) {
            if (this->_tools[it]->getToggle() == true) {
                if (this->_tools[it] == this->_currentTool) {
                    switch ((int) this->_screenSetup) {
                        case InterfaceTool::ScreenSetup::NONE:
                            break;
                        case InterfaceTool::ScreenSetup::WIDE:
                            wattron(_window, COLOR_PAIR(5));
                            rectangle((COLS - COLS + 15), 1, (COLS - 2), (LINES - 2), _window);
                            wattroff(_window, COLOR_PAIR(5));
                            wattron(_window, COLOR_PAIR(16));
                            mvwprintw(_window, (LINES - 2), (COLS - COLS + 15), this->_tools[it]->getName());
                            wattroff(_window, COLOR_PAIR(16));
                            break;
                    }
                } else {
                    switch ((int) this->_screenSetup) {
                        case InterfaceTool::ScreenSetup::NONE:
                            break;
                        case InterfaceTool::ScreenSetup::WIDE:
                            rectangle((COLS - COLS + 15), 1, (COLS - 2), (LINES - 2), _window);
                            break;
                    }
                }
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Uria error from InterfaceTool displaying module: " << e.what() << std::endl;
    }
    return;
}

void InterfaceTool::displayToolsWithoutMenuNav(WINDOW *_window)
{
    try {
        for (int it = 0; it != (int) this->_tools.size(); it++) {
            if (this->_tools[it]->getToggle() == true) {
                if (this->_tools[it] == this->_currentTool) {
                    switch ((int) this->_screenSetup) {
                        case InterfaceTool::ScreenSetup::NONE:
                            mvwprintw(_window, 7, 100, "InterfaceTool::ScreenSetup::NONE");
                            break;
                        case InterfaceTool::ScreenSetup::WIDE:
                            wattron(_window, COLOR_PAIR(3));
                            rectangle(1, 1, (COLS - 2), (LINES - 2), _window);
                            wattroff(_window, COLOR_PAIR(3));
                            mvwprintw(_window, 7, 100, "InterfaceTool::ScreenSetup::WIDE");
                            break;
                    }
                } else {
                    switch ((int) this->_screenSetup) {
                        case InterfaceTool::ScreenSetup::NONE:
                            break;
                        case InterfaceTool::ScreenSetup::WIDE:
                            rectangle((COLS - COLS + 15), 1, (COLS - 2), (LINES - 2), _window);
                            break;
                    }
                }
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Uria error from InterfaceTool displaying module: " << e.what() << std::endl;
    }
    return;
}


void InterfaceTool::displayToolsWithoutMenuTyp(WINDOW *_window)
{
    try {
        for (int it = 0; it != (int) this->_tools.size(); it++) {
            if (this->_tools[it]->getToggle() == true) {
                if (this->_tools[it] == this->_currentTool) {
                    switch ((int) this->_screenSetup) {
                        case InterfaceTool::ScreenSetup::NONE:
                            mvwprintw(_window, 7, 100, "InterfaceTool::ScreenSetup::NONE");
                            break;
                        case InterfaceTool::ScreenSetup::WIDE:
                            wattron(_window, COLOR_PAIR(5));
                            rectangle(1, 1, (COLS - 2), (LINES - 2), _window);
                            wattroff(_window, COLOR_PAIR(5));
                            wattron(_window, COLOR_PAIR(16));
                            mvwprintw(_window, (LINES - 2), 2, this->_tools[it]->getName());
                            wattroff(_window, COLOR_PAIR(16));
                            mvwprintw(_window, 7, 100, "InterfaceTool::ScreenSetup::WIDE");
                            break;
                    }
                } else {
                    switch ((int) this->_screenSetup) {
                        case InterfaceTool::ScreenSetup::NONE:
                            break;
                        case InterfaceTool::ScreenSetup::WIDE:
                            rectangle((COLS - COLS + 15), 1, (COLS - 2), (LINES - 2), _window);
                            break;
                    }
                }
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Uria error from InterfaceTool displaying module: " << e.what() << std::endl;
    }
    return;
}


InterfaceTool::InterfaceTool()
{
    Tool *notepad = new Tool("NOTEPAD");
    Tool *reminder = new Tool("REMINDER");
    Tool *calendar = new Tool("CALENDAR");

    this->myfile.open("test.txt");

    this->_tools.push_back(notepad);
    this->_tools.push_back(reminder);
    this->_tools.push_back(calendar);
    this->_screenSetup = InterfaceTool::ScreenSetup::NONE;
    this->_keyboardMode = InterfaceTool::KeyboardScope::NAVIGATION;
    this->_menu = new Menu(this->_tools);
    this->_currentTool = nullptr;
}

InterfaceTool::InterfaceTool(WINDOW *window)
{
    Tool *notepad = new Tool("NOTEPAD");
    Tool *reminder = new Tool("REMINDER");
    Tool *calendar = new Tool("CALENDAR");

    this->myfile.open("test.txt");

    this->_window = window;
    this->_tools.push_back(notepad);
    this->_tools.push_back(reminder);
    this->_tools.push_back(calendar);
    this->_screenSetup = InterfaceTool::ScreenSetup::NONE;
    this->_keyboardMode = InterfaceTool::KeyboardScope::NAVIGATION;
    this->_menu = new Menu(this->_tools);
    this->_currentTool = nullptr;
}

InterfaceTool::~InterfaceTool()
{
    for (auto it = this->_tools.begin(); it != this->_tools.end(); it++) {
        Tool *tmp = *it;
        delete tmp;
    }
    this->myfile.close();
}

void InterfaceTool::setKBMode(void)
{
    switch (this->_keyboardMode) {
        case InterfaceTool::KeyboardScope::TYPING:
            this->_keyboardMode = InterfaceTool::KeyboardScope::NAVIGATION;
            break;
        case InterfaceTool::KeyboardScope::NAVIGATION:
            this->_keyboardMode = InterfaceTool::KeyboardScope::TYPING;
            break;
    }
    return;
}

void InterfaceTool::changeCurrentToolLeft(void)
{
    try {
        if (this->_currentTool == nullptr) {
            for (int i = (int) this->_tools.size() - 1; i >= 0; i--) {
                if (this->_tools[i]->getToggle() == true) {
                    this->_currentTool = this->_tools[i];
                    return;
                }
            }
            return;
        }
        for (int it = 0; it <= (int) this->_tools.size()- 1; it++) {
            if (this->_tools[it] == this->_currentTool) {
                for (int i = it - 1; i >= 0; i--) {
                    if (this->_tools[i]->getToggle() == true) {
                        this->_currentTool = this->_tools[i];
                        return;
                    }
                }
                if (this->_menu->getToggle() == true) {
                    this->_currentTool = nullptr;
                } else {
                    for (int n = (int) this->_tools.size() - 1; n >= 0; n--) {
                        if (this->_tools[n]->getToggle() == true) {
                            this->_currentTool = this->_tools[n];
                            return;
                        }
                    }
                }
                return;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Uria error from InterfaceTool module: " << e.what() << std::endl;
    }
    return;
}

void InterfaceTool::changeCurrentToolRight(void)
{
    try {
        if (this->_currentTool == nullptr) {
            for (int i = 0; i <= (int) this->_tools.size() - 1; i++) {
                if (this->_tools[i]->getToggle() == true) {
                    this->_currentTool = this->_tools[i];
                    return;
                }
            }
            return;
        }
        for (int it = 0; it <= (int) this->_tools.size() - 1; it++) {
            if (this->_tools[it] == this->_currentTool) {
                for (int i = it + 1; i <= (int) this->_tools.size() - 1; i++) {
                    if (this->_tools[i]->getToggle() == true) {
                        this->_currentTool = this->_tools[i];
                        return;
                    }
                }
                if (this->_menu->getToggle() == true) {
                    this->_currentTool = nullptr;
                } else {
                    for (int i = 0; i <= (int) this->_tools.size() - 1; i++) {
                        if (this->_tools[i]->getToggle() == true) {
                            this->_currentTool = this->_tools[i];
                            return;
                        }
                    }
                }
                return;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Uria error from InterfaceTool module: " << e.what() << std::endl;
    }
    return;
}

Tool *InterfaceTool::getSpecificTool(const char *name)
{
    for (auto it = this->_tools.begin(); it != this->_tools.end(); it++) {
        Tool *tmp = *it;
        if (std::strcmp(tmp->getName(), name) == 0) {
            return (tmp);
        }
    }
    return (nullptr);
}

int InterfaceTool::initTools()
{
    return (0);
}

int InterfaceTool::getCurrentToolIndex(void)
{
    for (int it = 0; it <= (int) this->_tools.size() - 1; it++) {
        if (this->_tools[it] == this->_currentTool)
            return (it);
    }
    return (0);
}

int InterfaceTool::handleInputsTyping(Keys::Key event)
{
    switch ((int) event) {
        //case (event < 26):
        //    return (1);
    }
    return (0);
}

int InterfaceTool::handleInputsNav(Keys::Key event)
{
    switch ((int) event) {
        case Keys::Key::K_CLOSE:
            if (this->_menu->getToggle() == true) {
                if (this->_currentTool == nullptr) {
                    this->_menu->setToogle();
                    for (int n = (int) this->_tools.size() - 1; n >= 0; n--) {
                        if (this->_tools[n]->getToggle() == true) {
                            this->_currentTool = this->_tools[n];
                            return (0);
                        }
                    }
                } else {
                    int index = this->getCurrentToolIndex();
                    for (int n = index - 1; n >= 0; n--) {
                        if (this->_tools[n]->getToggle() == true) {
                            this->_currentTool = this->_tools[n];
                            return (0);
                        }
                    }
                    this->_currentTool = nullptr;
                }
            } else {
                int index = this->getCurrentToolIndex();
                for (int n = index - 1; n >= 0; n--) {
                    if (this->_tools[n]->getToggle() == true) {
                        this->_currentTool = this->_tools[n];
                        return (0);
                    }
                }
                for (int n = (int) this->_tools.size() - 1; n >= index; n--) {
                    if (this->_tools[n]->getToggle() == true) {
                        this->_currentTool = this->_tools[n];
                        return (0);
                    }
                }
            }
            break;
        case Keys::Key::K_LEFT:
            this->changeCurrentToolLeft();
            break;
        case Keys::Key::K_RIGHT:
            this->changeCurrentToolRight();
            break;
        case Keys::Key::K_CONTROL:
            this->_menu->setToogle();
            break;

        case Keys::Key::K_RETURN:
            if (this->_menu->getToggle() == true) {
                if (this->_menu->getHighlightedTool() != this->_currentTool) {
                    // else if ScreenSetup::SPLITED_V
                        // if selectedToolType = TOP
                            // unable unused tool (TYPE TOP)
                            // enable selected tool
                        // else if selectedToolType = BOT
                            // unable unused tool (TYPE BOT)
                            // enable selected tool
                    // else if ScreenSetup::SPLITED_H
                    // else if ScreenSetup::SPLITED_VH
                    if (this->_screenSetup == InterfaceTool::ScreenSetup::NONE) {
                        this->_menu->getHighlightedTool()->setToggle(true);
                        this->_currentTool = this->_menu->getHighlightedTool();
                        this->_screenSetup = InterfaceTool::ScreenSetup::WIDE;
                        return (0);
                    } else if (this->_screenSetup == InterfaceTool::ScreenSetup::WIDE) {
                        this->_tools[this->getCurrentToolIndex()]->setToggle(false);
                        this->_menu->getHighlightedTool()->setToggle(true);
                        this->_currentTool = this->_tools[this->getCurrentToolIndex()];
                        return (0);
                    }
                    // if ScreenSetup::WIDE
                        // if enabled Tool is Top and selected to is Top || enabled Tool is Bot and selected to is Bot
                            // this->_screenSetup = InterfaceTool::ScreenSetup::SPLITED_V;
                        // if . . . Top ... Bot || ... Bot ... Top
                            // this->_screenSetup = InterfaceTool::ScreenSetup::SPLITED_H;
                        // enable selected tool
                        // enable selected tool
                    this->_currentTool = this->_menu->getHighlightedTool();
                }
            }
            break;
        default:
            //if the Menu tool is active
            if (this->_menu->getToggle() == true) {
                // The following functions allow us to navigate vertically in the menu
                if (event == Keys::Key::K_UP) {
                    this->_menu->changeMenuToolSelectionAbove(this->_menu->getHighlightedTool());
                    return (0);
                } else if (event == Keys::Key::K_DOWN) {
                    this->_menu->changeMenuToolSelectionBelow(this->_menu->getHighlightedTool());
                    return (0);
                }
                if (this->_currentTool == nullptr) {
                    // if there's no current tool set
                    if (event == Keys::Key::K_RETURN) {
                            break;
                    }
                } //else if (this->_currentTool != nullptr) {}
            } else {
                //if the Menu tool is not active
            }
        break;
    }
    return (0);
}

int InterfaceTool::update(Keys::Key event)
{
    switch ((int) event) {
        case Keys::K_M:
            this->_menu->setToogle();
            break;
        case Keys::K_CONTROL:
            this->setKBMode();
            break;
        default:
            if (this->_keyboardMode == InterfaceTool::KeyboardScope::NAVIGATION) {
                this->handleInputsNav(event);
            } else if (this->_keyboardMode == InterfaceTool::KeyboardScope::TYPING) {
                this->handleInputsTyping(event);
            }
            break;
    }
    return (0);
}

int InterfaceTool::render(WINDOW *_window)
{
    wclear(_window);
    //Global rectangle frame
    rectangle(0, 0, (COLS - 1), (LINES - 1), _window);
    //Menu config
    //Tool *notepad_tool = this->getSpecificTool("NOTEPAD");
    //Tool *reminder_tool = this->getSpecificTool("REMINDER");
    //Tool *calendar_tool = this->getSpecificTool("CALENDAR");
    if (this->_keyboardMode == InterfaceTool::KeyboardScope::TYPING) {
        if (this->_menu->getToggle() == true) {
            if (this->_currentTool == nullptr) {
                this->_menu->displayMenuTyping(_window);
                mvwprintw(_window, 6, 100, "displayMenuTyping");
                mvwprintw(_window, 8, 100, this->screenSetupToString());
            } else if (this->_currentTool != nullptr) {
                this->_menu->displayMenu(_window);
                this->displayToolsWithMenuTyp(_window);
                mvwprintw(_window, 8, 100, this->screenSetupToString());
                mvwprintw(_window, 6, 100, "displayToolsWithMenuTyp");
            }
        } else {
            this->displayToolsWithoutMenuTyp(_window);
            mvwprintw(_window, 8, 100, this->screenSetupToString());
            mvwprintw(_window, 6, 100, "displayToolsWithoutMenuTyp");
        }
    } else if (this->_keyboardMode == InterfaceTool::KeyboardScope::NAVIGATION) {
        if (this->_menu->getToggle() == true) {
            if (this->_currentTool == nullptr) {
                this->_menu->displayMenuNavSelected(_window);
                this->displayToolsWithMenuNav(_window);
                mvwprintw(_window, 6, 100, "displayToolsWithMenuNav");
                mvwprintw(_window, 8, 100, this->screenSetupToString());
            } else if (this->_currentTool != nullptr) {
                this->_menu->displayMenu(_window);
                this->displayToolsWithMenuNav(_window);
                mvwprintw(_window, 6, 100, "displayToolsWithMenuNav");
                mvwprintw(_window, 8, 100, this->screenSetupToString());
            }
        } else {
            this->displayToolsWithoutMenuNav(_window);
            mvwprintw(_window, 6, 100, "displayToolsWithoutMenuNav");
            mvwprintw(_window, 8, 100, this->screenSetupToString());
        }
        //else if (this->_menu->getToggle() == true && this->_currentTool != nullptr) {
        //}
    }
    wrefresh(_window);
    return (0);
}