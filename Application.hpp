#pragma once

#include "dir.hpp"
#include "JSONManager.hpp"
#include "MultimediaSearch.hpp"

class Application {
public:
    void StartSettings();
    void MainLoop();
    std::string& GetPath() { return m_directoryPath; }
    unsigned int& GetTime() {return m_repeatTime; }
private:
    JSONManager m_js;
    MultimediaSearch m_ms;
    std::string m_directoryPath;
    unsigned int m_repeatTime;
};