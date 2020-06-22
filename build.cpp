#include "compiler.h"
#include "api/api.h"
#include "defer.h"
#include "format.h"

#include <win_error.h>
#include <cstdlib>
#include <Windows.h>
#include <filesystem>

int main(int arg_count, char const** args) {
    using namespace std::filesystem;
    
    path exe_path(_pgmptr);
    path project_path = current_path();
    path linker_search_path(exe_path.parent_path());
    path builder_output_lib_path(project_path / "build_temp.dll");

    auto compiler_exit_code = compile("gcc", linker_search_path, project_path);
    defer(panic_if_win_null(DeleteFileW(builder_output_lib_path.c_str())));

    if(compiler_exit_code != 0) {
        return compiler_exit_code;
    }
    
    printv("Loading dll %", builder_output_lib_path.string());

    using build_func_signature = bool (*)();
    auto lib = panic_if_win_null(LoadLibraryW(builder_output_lib_path.c_str()));
    defer(panic_if_win_null(FreeLibrary(lib)));
    auto build_func = panic_if_win_null(GetProcAddress(lib, "build"));

    bool build_success = ((build_func_signature) build_func)();

    if(build_success) {
        puts("Build completed successfully.");
    } else {
        puts("Build failed.");
    }
}