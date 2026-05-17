#pragma once

#include "dir.hpp"
#include "JSONManager.hpp"
#include "MultimediaSearch.hpp"

class Application {
public:
    void StartSettings(std::string& dir_path, unsigned int& interval);
    void MainLoop(std::vector<std::string> files);
private:
    JSONManager m_js;
    MultimediaSearch m_ms;
};