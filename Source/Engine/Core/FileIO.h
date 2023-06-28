#pragma once
#include <filesystem>
#include <string>
namespace meow {
	std::string getFilePath() { return std::filesystem::current_path().string(); }
}