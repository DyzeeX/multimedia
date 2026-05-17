#include "JSONManager.hpp"

#include <fstream>

JSONManager::JSONManager(){
    m_json = {
        {"audio", nlohmann::json::array()},
        {"video", nlohmann::json::array()},
        {"images", nlohmann::json::array()}
    };
}

// cases: 
// 1 - audio file
// 2 - video file
// 3 - image file
void JSONManager::AddMultimediaFile(std::string file_name, char type) {
    switch (type) {
        case 1 : 
        if (!m_json["audio"].is_array()) m_json["audio"] = nlohmann::json::array();
            m_json["audio"].push_back(file_name);
            break;
        case 2 : 
        if (!m_json["video"].is_array()) m_json["video"] = nlohmann::json::array();
            m_json["video"].push_back(file_name);
            break;
        case 3 : 
        if (!m_json["images"].is_array()) m_json["images"] = nlohmann::json::array();
            m_json["images"].push_back(file_name);
            break;
    }
}

void JSONManager::CreateJSONFile(const char* dir_path) {
    std::string full_path = std::string(dir_path);
    if (!full_path.empty() && full_path.back() != '/') {
        full_path += "/"; 
    }

    full_path += json_file_name;

    std::ofstream o(full_path);

    if(o.is_open()) {
        o << m_json.dump(4);
    }
}