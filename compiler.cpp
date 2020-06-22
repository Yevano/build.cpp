#include "compiler.h"

#include <format.h>
#include <filesystem>

int compile(std::string const& compiler, std::filesystem::path const& linker_search_path, std::filesystem::path const& project_path) {
    if(compiler == "gcc") {
        auto build_api_include_path_arg = linker_search_path.parent_path().concat("api").string();
        auto project_path_arg = project_path.string();
        auto linker_search_path_arg = linker_search_path.string();
        return std::system(formatv(
            "g++ -std=c++2a -shared -I\"%\" \"%\" -o build_temp.dll -L\"%\" -llibbuild.cpp",
            build_api_include_path_arg,
            project_path_arg,
            linker_search_path_arg
        ).c_str());
    }

    return 0;
}