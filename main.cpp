#include <iostream>

#include <magic.h>

#include "Application.hpp"

int main() {
    std::string directory_path;
    unsigned int repeat_time;

    auto app = std::make_unique<Application>();
    auto js = std::make_unique<JSONManager>();
    auto ms = std::make_unique<MultimediaSearch>();

    app->StartSettings(directory_path, repeat_time);
    
    auto r = serarchFilesPathInDirectory(directory_path.c_str());

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