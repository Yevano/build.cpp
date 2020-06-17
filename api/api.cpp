#include "api.h"

#include <cstdlib>

__declspec(dllexport) int run(std::string const& command) {
    return std::system(command.c_str());
}