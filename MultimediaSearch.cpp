#include "MultimediaSearch.hpp"

MultimediaSearch::MultimediaSearch() {
    magic_cookie = magic_open(MAGIC_MIME_TYPE);
    magic_load(magic_cookie, nullptr);
}

std::pair<bool, char> MultimediaSearch::IsMultimedia(const char* file_name) {
    
}

MultimediaSearch::~MultimediaSearch() {
    magic_close(magic_cookie);
}