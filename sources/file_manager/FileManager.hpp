#include <iostream>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <utility>
#include <vector>
#include <string>
#include <sys/stat.h>

#ifndef FILEMANAGER_HPP_
#define FILEMANAGER_HPP_

#include "Crypt.hpp"
#include "Files.hpp"
#include "Keys.hpp"
#include "Core.hpp"

class FileManager {
    public:
        // Constructor
        FileManager();
        ~FileManager();

        int update(Keys::Key);
        std::string read();
        void write(const char *);
        void remove(void);

        //TODO:
        int catchSpecialEvent(Keys::Key);
        int specialEventHandler(int);
        Files *getCurrentFile(std::string);
        //void changeCurrentFile(std::string);
        //void switchCurrentFile(void);
        void save(std::string, std::string);
        void saveAll(void);

    private:
        std::string _currentFileName;
        std::vector<std::pair<std::string, Files>> _files;
        std::string _dir;
        std::ofstream _out;
        std::string _textBuffer;
        //DirectoryManager
};

#endif