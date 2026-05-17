#include <iostream>

#include <magic.h>

#include "dir.hpp"
#include "JSONManager.hpp"
#include "MultimediaSearch.hpp"

int main() {

    auto js = std::make_unique<JSONManager>();
    auto r = serarchFilesPathInDirectory("/home/dyzeex/test");

    auto ms = std::make_unique<MultimediaSearch>();
    for(auto& str : r){
        auto [is_media, type] = ms->IsMultimedia(str.c_str());
        if(is_media){
            size_t slash_pos = str.find_last_of ('/');
            if (slash_pos != std::string::npos && slash_pos != 0) {
                str = str.substr(slash_pos + 1);
            }
            js->AddMultimediaFile(str, type);
        }
    }
    js->CreateJSONFile();
    return 0;
} 