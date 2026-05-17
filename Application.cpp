#include "Application.hpp"

#include <iostream>

void Application::StartSettings(std::string& dir_path, unsigned int& interval) {
    bool correct_path = false;
    bool correct_time = false;

    while (!correct_path || !correct_time) {
        // path
        if (!correct_path){
            std::cout << "Please, enter the full directory path: ";
            std::getline(std::cin >> std::ws, dir_path);

            if(isDirectoryExist(dir_path.c_str())) {
                correct_path = true;
            } else {
                std::cout << "Can't open '" << dir_path << "' directory.";
            }
        }

        // time
        if (correct_path && !correct_time) {
            std::cout << "Please, enter the repeat time in seconds: ";
            std::string input;
            std::cin >> input;

            try {
                size_t pos = 0;
                unsigned long long value = std::stoull(input, &pos);

                if (pos != input.size()) {
                    std::cout << "Invalid time! Value not a number.\n";
                } 
                else if (value == 0 || value > std::numeric_limits<unsigned int>::max()) {
                    std::cout << "Invalid time! Enter an integer number (1 . . . "
                              << std::numeric_limits<unsigned int>::max() << ").\n";
                } 
                else {
                    interval = static_cast<unsigned int>(value);
                    correct_time = true;
                }
            } catch (const std::invalid_argument&) {
                std::cout << "Invalid time! Value not a number.\n";
            } catch (const std::out_of_range&) {
                std::cout << "Invalid time! Number is too large.\n";
            }

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void Application::MainLoop(std::vector<std::string> files) {

}