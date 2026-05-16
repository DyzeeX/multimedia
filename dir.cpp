#include "dir.hpp"

#include <cstring>

#include <sys/stat.h>
#include <dirent.h>

std::string getExtention(const char* file) {
    std::string res(file);
    
    size_t dot_pos = res.find_last_of ('.');
    if (dot_pos != std::string::npos && dot_pos != 0) {
        res = res.substr(dot_pos + 1);
        return res;
    }
    return "";
}

std::vector<std::string> serarchFFileNamesInDirectory(const char* dir_path){
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
            auto sub = serarchFFileNamesInDirectory(temp_path.c_str());
           result.insert(result.end(), sub.begin(), sub.end());
        } else if (S_ISREG(st.st_mode)){
            result.push_back(getExtention(dr->d_name));
        }
    }

    closedir(dir);
    return result;
}