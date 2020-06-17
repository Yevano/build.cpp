#include "compiler.h"

#include <format.h>

int compile(std::string const& compiler, std::filesystem::path const& file_path) {
    if(compiler == "gcc") {
        return std::system(formatv("gcc -std=c++2a -shared -Iapi % -o build_temp.dll -L. -llibbuild.cpp", file_path.string()).c_str());
    }

    return 0;
}