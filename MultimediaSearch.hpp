#pragma once 

#include <utility>
#include <magic.h>

class MultimediaSearch {
public:
    MultimediaSearch();
    ~MultimediaSearch();
    
    std::pair<bool, char> IsMultimedia(const char* file_name) const;
private:
    magic_t magic_cookie;
};