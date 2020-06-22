#include "compiler.h"

#include <format.h>
#include <filesystem>

int compile(std::string const& compiler, std::filesystem::path const& linker_search_path, std::filesystem::path const& project_path) {
    if(compiler == "gcc") {
        auto build_api_include_path = linker_search_path.parent_path() / "api";
        auto builder_path = project_path / "builder.cpp";
        auto build_api_include_path_arg = build_api_include_path.string();
        auto builder_path_arg = builder_path.string();
        auto linker_search_path_arg = linker_search_path.string();
        
        auto command = formatv(
            "g++ -std=c++2a -shared -I\"%\" \"%\" -o build_temp.dll -L\"%\" -llibbuild.cpp",
            build_api_include_path_arg,
            builder_path_arg,
            linker_search_path_arg);
        
        printv("> %", command);

        return std::system(command.c_str());
    }

    return 0;
}