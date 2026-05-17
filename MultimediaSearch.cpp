#include "MultimediaSearch.hpp"

#include <string>

MultimediaSearch::MultimediaSearch() {
    magic_cookie = magic_open(MAGIC_MIME_TYPE);
    magic_load(magic_cookie, nullptr);
}

std::pair<bool, char> MultimediaSearch::IsMultimedia(const char* file_name) {
    const char* mime_type = magic_file(magic_cookie, file_name);

    if (mime_type == nullptr) return {false, -1};
    
    std::string format(mime_type);
    
    size_t slash_pos = format.find_last_of ('/');
    if (slash_pos != std::string::npos && slash_pos != 0) {
        format = format.substr(0, slash_pos);
    }

    char res_format = -1;
    bool is_multimedia = false;

    if (format == "audio") {
        res_format = 1;
        is_multimedia = true;
    } 
    else if (format == "video") {
        res_format = 2;
        is_multimedia = true;
    } 
    else if (format == "image") {
        res_format = 3;
        is_multimedia = true;
    }

    return  { is_multimedia, res_format };
}

MultimediaSearch::~MultimediaSearch() {
    magic_close(magic_cookie);
}