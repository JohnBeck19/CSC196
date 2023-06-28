#include "FileIO.h"


using namespace meow;

std::string meow::getFilePath()
{
	return std::filesystem::current_path().string();
}
