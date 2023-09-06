#include <iostream>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <utility> // For std::pair
#include <vector>
#include <string>
#include <sys/stat.h>

#ifndef FILES_HPP_
#define FILES_HPP_

class Files {
    public:
        Files(std::string);
        Files(std::string, std::string);
        ~Files();

        bool isCached(void);
        std::string getContent(void);
        void setContent(std::string);
    private:
        std::string _content;
        std::string _name;

};

#endif