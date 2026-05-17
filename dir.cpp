#include "dir.hpp"

#include <cstring>

#include <sys/stat.h>
#include <dirent.h>

std::vector<std::string> serarchFilesInDirectory(const char* dir_path){
    std::vector<std::string> result{};

    struct stat st;
    struct dirent *dr;
    DIR* dir;
    dir = opendir(dir_path);
    
    while((dr = readdir(dir)) != 0) {
        if (std::strcmp(dr->d_name, ".") == 0 || std::strcmp(dr->d_name, "..") == 0){
            continue;
        }

        std::string temp_path = std::string(dir_path) + '/' + dr->d_name;
        if (lstat(temp_path.c_str(), &st) == -1) {
            continue;
        }

        if(S_ISDIR(st.st_mode)){
           serarchFilesInDirectory(temp_path.c_str());
        } else if (S_ISREG(st.st_mode)){
            result.push_back(dr->d_name);
        }
    }

    closedir(dir);
    return result;
}