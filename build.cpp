#include "compiler.h"
#include "api/api.h"

#include <win_error.h>
#include <cstdlib>
#include <Windows.h>

int main(int arg_count, char const** args) {
    auto compiler_exit_code = compile("gcc", "builder.cpp");
    
    auto lib = panic_if_win_null(LoadLibraryA("build_temp.dll"));
    auto build_func = panic_if_win_null(GetProcAddress(lib, "build"));
    ((void (*)()) build_func)();
}