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
#include "Ncurses.hpp"

void writeTextBufferWithMenu(WINDOW *_window, std::string buffer, screenCoords_t coords)
{
  int x = coords.tool_origin_x_menu_active + 1;
  int y = coords.tool_origin_y_menu_active + 1;
  int bufferMaxlength = coords.size_x - 19;

  for (unsigned chunk_size = 0; chunk_size < buffer.length(); chunk_size += bufferMaxlength) {
    std::string line = buffer.substr(chunk_size, bufferMaxlength); //seg faulf because string too short
    mvwprintw(_window, y, x, line.c_str());
    y++;
  }
}

void InterfaceTool::displayToolsWithMenuNav(WINDOW *_window)
{
    try {
        for (int it = 0; it != (int) this->_tools.size(); it++) {
            mvwprintw(_window, 9 + it , 100, this->_tools[it]->getName());
            mvwprintw(_window, 9 + it , 150, this->_tools[it]->getToggle() == true ? "true" : "false");
            if (this->_tools[it]->getToggle() == true) {
                mvwprintw(_window, 15 , 150, this->_tools[this->getCurrentToolIndex()]->getName());
                //mvwprintw(_window, 16 , 150, this->_currentTool->getName());
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
                            rectangle(
                                this->_coords.tool_origin_x_menu_active,
                                this->_coords.tool_origin_y_menu_active,
                                this->_coords.tool_end_x_menu_active,
                                this->_coords.tool_end_y_menu_active,
                                _window
                            );
                            //mvwprintw(_window, 25 , 25, this->_currentTool->getCursorChar());
                            wattroff(_window, COLOR_PAIR(5));
                            wattron(_window, COLOR_PAIR(16));
                            mvwprintw(_window, (LINES - 2), (COLS - COLS + 15), this->_tools[it]->getName());
                            wattroff(_window, COLOR_PAIR(16));
                            writeTextBufferWithMenu(_window, this->_currentTool->getBuffer(), _coords);
                            //mvwprintw(_window, this->_currentTool->getCursor().at(0) , this->_currentTool->getCursor().at(1), this->_currentTool->getBuffer().c_str());
                            //myfile << this->_currentTool->getCursorChar() << std::endl;
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

    //this->myfile.open("test.txt");

    this->_tools.push_back(notepad);
    this->_tools.push_back(reminder);
    this->_tools.push_back(calendar);
    this->_screenSetup = InterfaceTool::ScreenSetup::NONE;
    this->_keyboardMode = InterfaceTool::KeyboardScope::NAVIGATION;
    this->_menu = new Menu(this->_tools);
    this->_currentTool = nullptr;
    this->_fileManager = new FileManager();
}

InterfaceTool::InterfaceTool(WINDOW *window)
{
    Tool *notepad = new Tool("NOTEPAD");
    Tool *reminder = new Tool("REMINDER");
    Tool *calendar = new Tool("CALENDAR");

    //this->myfile.open("test.txt");

    this->_window = window;
    this->_tools.push_back(notepad);
    this->_tools.push_back(reminder);
    this->_tools.push_back(calendar);
    this->_screenSetup = InterfaceTool::ScreenSetup::NONE;
    this->_keyboardMode = InterfaceTool::KeyboardScope::NAVIGATION;
    this->_menu = new Menu(this->_tools);
    this->_currentTool = nullptr;
    this->_fileManager = new FileManager();
}

InterfaceTool::InterfaceTool(WINDOW *window, int row, int col) {

    Tool *notepad = new Tool("NOTEPAD");
    Tool *reminder = new Tool("REMINDER");
    Tool *calendar = new Tool("CALENDAR");

    this->_window = window;
    this->_tools.push_back(notepad);
    this->_tools.push_back(reminder);
    this->_tools.push_back(calendar);
    this->_screenSetup = InterfaceTool::ScreenSetup::NONE;
    this->_keyboardMode = InterfaceTool::KeyboardScope::NAVIGATION;
    this->_menu = new Menu(this->_tools);
    this->_currentTool = nullptr;
    this->_fileManager = new FileManager();
    this->_x = col;
    this->_y = row;
}

InterfaceTool::~InterfaceTool()
{
    for (auto it = this->_tools.begin(); it != this->_tools.end(); it++) {
        Tool *tmp = *it;
        delete tmp;
    }
    //this->myfile.close();
    delete this->_fileManager;
    delete this->_menu;
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

FileManager *InterfaceTool::fileManager(void) {
    return (this->_fileManager);
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

void InterfaceTool::toogleOffAllTools(void)
{
    for (int it = 0; it <= (int) this->_tools.size() - 1; it++) {
        this->_tools[it]->setToggle(false);
    }
    return;
}

int InterfaceTool::initTools()
{
    return (0);
}

int InterfaceTool::initCoods()
{
    this->_coords = {};
    this->_coords.size_x = this->_x;
    this->_coords.size_y = this->_y;
    this->_coords.menu_origin_x = 1;
    this->_coords.menu_origin_y = 1;
    this->_coords.menu_end_x = 14;
    this->_coords.menu_end_y = (this->_y - 2);
    this->_coords.tool_origin_x_menu_active = 15;
    this->_coords.tool_origin_y_menu_active = 1;
    this->_coords.tool_origin_x_menu_unactive = 1;
    this->_coords.tool_origin_y_menu_unactive = 1;
    this->_coords.tool_end_x_menu_active = (this->_x - 2);
    this->_coords.tool_end_y_menu_active = (this->_y - 2);
    this->_coords.tool_end_x_menu_unactive = (this->_x - 2);
    this->_coords.tool_end_y_menu_unactive = (this->_y - 2);

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
    //this->_currentTool->setCursorChar('');

    switch ((int) event) {
        case Keys::K_UP:
        case Keys::K_CLOSE:
        case Keys::K_DOWN:
        case Keys::K_LEFT:
        case Keys::K_RIGHT:
        case Keys::K_RETURN:
        case Keys::K_EXIT:
        case Keys::K_UNDEFINED:
        case Keys::K_CONTROL:
            //delete queue when handling a sequence of special events
          return (3);
          break;
        case Keys::K_BACKSPACE:
          //handle deleting 1 char
          this->_currentTool->popBuffer();
          return (1);
          break;
        default:
            case Keys::K_A:
                this->_currentTool->setCursorChar('a');
                this->_currentTool->appendBuffer('a');
                return (0);
            case Keys::K_B:
                this->_currentTool->setCursorChar('b');
                this->_currentTool->appendBuffer('b');
                return (0);
            case Keys::K_C:
                this->_currentTool->setCursorChar('c');
                this->_currentTool->appendBuffer('c');
                return (0);
            case Keys::K_D:
                this->_currentTool->setCursorChar('d');
                this->_currentTool->appendBuffer('d');
                return (0);
            case Keys::K_E:
                this->_currentTool->setCursorChar('e');
                this->_currentTool->appendBuffer('e');
                return (0);
            case Keys::K_F:
                this->_currentTool->setCursorChar('f');
                this->_currentTool->appendBuffer('f');
                return (0);
            case Keys::K_G:
                this->_currentTool->setCursorChar('g');
                this->_currentTool->appendBuffer('g');
                return (0);
            case Keys::K_H:
                this->_currentTool->setCursorChar('h');
                this->_currentTool->appendBuffer('h');
                return (0);
            case Keys::K_I:
                this->_currentTool->setCursorChar('i');
                this->_currentTool->appendBuffer('i');
                return (0);
            case Keys::K_J:
                this->_currentTool->setCursorChar('j');
                this->_currentTool->appendBuffer('j');
                return (0);
            case Keys::K_K:
                this->_currentTool->setCursorChar('k');
                this->_currentTool->appendBuffer('k');
                return (0);
            case Keys::K_L:
                this->_currentTool->setCursorChar('l');
                this->_currentTool->appendBuffer('l');
                return (0);
            case Keys::K_M:
                this->_currentTool->setCursorChar('m');
                this->_currentTool->appendBuffer('m');
                return (0);
            case Keys::K_N:
                this->_currentTool->setCursorChar('n');
                this->_currentTool->appendBuffer('n');
                return (0);
            case Keys::K_O:
                this->_currentTool->setCursorChar('o');
                this->_currentTool->appendBuffer('o');
                return (0);
            case Keys::K_P:
                this->_currentTool->setCursorChar('p');
                this->_currentTool->appendBuffer('p');
                return (0);
            case Keys::K_Q:
                this->_currentTool->setCursorChar('q');
                this->_currentTool->appendBuffer('q');
                return (0);
            case Keys::K_R:
                this->_currentTool->setCursorChar('r');
                this->_currentTool->appendBuffer('r');
                return (0);
            case Keys::K_S:
                this->_currentTool->setCursorChar('s');
                this->_currentTool->appendBuffer('s');
                return (0);
            case Keys::K_T:
                this->_currentTool->setCursorChar('t');
                this->_currentTool->appendBuffer('t');
                return (0);
            case Keys::K_U:
                this->_currentTool->setCursorChar('u');
                this->_currentTool->appendBuffer('u');
                return (0);
            case Keys::K_V:
                this->_currentTool->setCursorChar('v');
                this->_currentTool->appendBuffer('v');
                return (0);
            case Keys::K_W:
                this->_currentTool->setCursorChar('w');
                this->_currentTool->appendBuffer('w');
                return (0);
            case Keys::K_X:
                this->_currentTool->setCursorChar('x');
                this->_currentTool->appendBuffer('x');
                return (0);
            case Keys::K_Y:
                this->_currentTool->setCursorChar('y');
                this->_currentTool->appendBuffer('y');
                return (0);
            case Keys::K_Z:
                this->_currentTool->setCursorChar('z');
                this->_currentTool->appendBuffer('z');
                return (0);
            case Keys::K_SPACE:
                this->_currentTool->setCursorChar(' ');
                this->_currentTool->appendBuffer(' ');
                return (0);
            break;
    }
    return (0);
}

int InterfaceTool::handleInputsNav(Keys::Key event)
{
    switch ((int) event) {
        case Keys::K_CLOSE:
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
                        this->toogleOffAllTools();
                        this->_currentTool = NULL;
                        this->_currentTool = this->_menu->getHighlightedTool();
                        this->_currentTool->setToggle(true);
                        return (0);
                    }
                    // if ScreenSetup::WIDE
                        // if enabled Tool is Top and selected to is Top || enabled Tool is Bot and selected to is Bot
                            // this->_screenSetup = InterfaceTool::ScreenSetup::SPLITED_V;
                        // if . . . Top ... Bot || ... Bot ... Top
                            // this->_screenSetup = InterfaceTool::ScreenSetup::SPLITED_H;
                        // enable selected tool
                        // enable selected tool
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
    int exitCode;

    exitCode = this->_fileManager->update(event);

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
                exitCode = this->handleInputsTyping(event);
                if (exitCode == 0) {
                    this->_currentTool->setCursor(this->_currentTool->findCursorNextPosition());
                }
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