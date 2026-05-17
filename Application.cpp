#include "Application.hpp"
#include "daemon.h"

#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>

void Application::StartSettings() {
    bool correct_path = false;
    bool correct_time = false;

    while (!correct_path || !correct_time) {
        // path
        if (!correct_path){
            std::cout << "Please, enter the full directory path: ";
            std::getline(std::cin >> std::ws, m_directoryPath);

            if(isDirectoryExist(m_directoryPath.c_str())) {
                correct_path = true;
            } else {
                std::cout << "Can't open '" << m_directoryPath << "' directory.";
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
                    m_repeatTime = static_cast<unsigned int>(value);
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

void Application::MainLoop() {
    StartSettings();
    Daemonize();
    
    std::vector<std::string> files;

    while(true){
        auto start = std::chrono::steady_clock::now();

        files.clear();
        m_js.Clear();

        files = serarchFilesPathInDirectory(m_directoryPath.c_str());

        for(auto& str : files){
            auto [is_media, type] = m_ms.IsMultimedia(str.c_str());
            if(is_media){
                size_t slash_pos = str.find_last_of ('/');
                if (slash_pos != std::string::npos && slash_pos != 0) {
                    str = str.substr(slash_pos + 1);
                }
                m_js.AddMultimediaFile(str, type);
            }
        }
        m_js.CreateJSONFile(m_directoryPath.c_str());

        auto end = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(end - start);

        auto sleep_time = std::chrono::seconds(m_repeatTime) - elapsed;
        if (sleep_time > std::chrono::seconds(0)) {
            std::this_thread::sleep_for(sleep_time);
        }
    }

}