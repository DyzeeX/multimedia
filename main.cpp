#include <iostream>
#include "dir.hpp"

int main(int argc, char* argv[]) {

    auto r = serarchFFileNamesInDirectory("/home/dyzeex/test");

    for(auto str : r){
        std::cout << str << std::endl; 
    }
    return 0;
} 