#pragma once

#include <string>

#include <nlohmann/json.hpp>

class JSONManager {
public:
    JSONManager();
    void AddMultimediaFile(std::string file_name, short type);
private:
    nlohmann::json m_json;
};