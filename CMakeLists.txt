cmake_minimum_required(VERSION 3.14)

project(multimedia LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(
        json 
        URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz 
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
        )
FetchContent_MakeAvailable(json)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(multimedia 
    "main.cpp"
    "dir.cpp"
    "JSONManager.cpp"
    "MultimediaSearch.cpp"
    )

find_library(MAGIC_LIBRARY NAMES magic REQUIRED)

target_link_libraries(multimedia PRIVATE 
    nlohmann_json::nlohmann_json
    ${MAGIC_LIBRARY}
)