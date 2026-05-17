#pragma once

#include <string>

#include <nlohmann/json.hpp>

class JSONManager {
public:
    JSONManager();
    void AddMultimediaFile(std::string file_name, char type);
    void CreateJSONFile(const char* dir_path = "/home/dyzeex/");
private:
    nlohmann::json m_json;
    const char* json_file_name = "media_files.json";
};