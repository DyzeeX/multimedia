#include <iostream>

#include "dir.hpp"
#include "JSONManager.hpp"

int main(int argc, char* argv[]) {

    auto js = std::make_unique<JSONManager>();
    auto r = serarchFilesInDirectory("/home/dyzeex/test");

    for(auto str : r){
        js->AddMultimediaFile(str, 1);    
    }
    js->CreateJSONFile();
    return 0;
} 