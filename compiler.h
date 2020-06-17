#pragma once

#include <string>
#include <filesystem>

int compile(std::string const& compiler, std::filesystem::path const& file_path);