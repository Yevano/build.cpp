#pragma once

#include <string>
#include <filesystem>

int compile(std::string const& compiler, std::filesystem::path const& linker_search_path, std::filesystem::path const& project_path);