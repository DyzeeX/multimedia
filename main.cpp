#include <iostream>
#include "dir.hpp"


int main(int argc, char* argv[]) {

    auto r = serarchFilesInDirectory("/home/dyzeex/test");

    for(auto str : r){
        std::cout << str << std::endl; 
    }
    return 0;
} 