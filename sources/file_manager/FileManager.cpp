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

#include "FileManager.hpp"
#include "Keys.hpp"


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>

FileManager::FileManager() {
    this->_dir = "filesave/";

    DIR* dir = opendir(this->_dir.c_str());
    if (dir == NULL) {
        std::cerr << "Could not open directory " << this->_dir << std::endl;
        exit(84);
    }
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        std::string filename = entry->d_name;
        std::pair<std::string, Files> file = std::make_pair(filename, Files(filename));
        _files.push_back(file);
    }
    this->_currentFileName = "test.txt";
    closedir(dir);
}

FileManager::~FileManager()
{
  this->_out.close();
}

int FileManager::catchSpecialEvent(Keys::Key event) {
  switch ((int) event) {
    case (Keys::K_CONTROL):
      return (1);
      break;
    case (Keys::K_BACKSPACE):
    case (Keys::K_RETURN):
      return (2);
      break;
    case (Keys::K_UNDEFINED):
      return (-1);
      break;
    default:
      return (0);
      break;
  }
};

int FileManager::specialEventHandler(int specialEvent) {
  switch (specialEvent) {
  case Keys::K_UP:
  case Keys::K_CLOSE:
  case Keys::K_DOWN:
  case Keys::K_LEFT:
  case Keys::K_RIGHT:
  case Keys::K_RETURN:
  case Keys::K_EXIT:
  case Keys::K_UNDEFINED:
  case Keys::K_CONTROL:
    return (3);
    break;
  case (Keys::K_BACKSPACE):
    this->remove();
    return (0);
    break;
  default:
    //delete queue when handling a sequence of special events
    return (0);
    break;
  }
};

int FileManager::update(Keys::Key event) {
    int specialEvent = this->catchSpecialEvent(event);
    if (specialEvent == 0) {
      //handle event as simple character to write

      this->write(eventToChar(event));
      //this->_textBuffer.append(eventToChar(event));
      //if (this->_textBuffer.length() > 5) {
      //  this->write(this->_textBuffer.c_str());
      //  this->_textBuffer.clear();
      //}
    } else if (specialEvent > 0) {
      return (this->specialEventHandler(specialEvent));
    } else {
      return (84);
    }
    return (0);
};

std::string FileManager::read() {
    std::ifstream in(this->_currentFileName);
    std::string contents((std::istreambuf_iterator<char>(in)),
                         std::istreambuf_iterator<char>());
    in.close();
    return contents;
};

        // Write to the file
void FileManager::write(const char *c) {
    this->_out.open(this->_currentFileName, std::ios::app);
    this->_out << c;
    this->_out.close();
};

        // Delete the contents of the file
void FileManager::remove(void) {
    this->_out.seekp(-1, std::ios_base::cur);
}

void FileManager::save(std::string){};

void FileManager::saveAll(){
  //for (this->_files) -> save("filename")
};
