#pragma once

#include <string>

struct Arguments {
	std::string inputFilePath, outputFilePath;
	int memorySize = 30000; // 30000 bytes is the default size
};

Arguments ArgumentParser(int argc, char* argv[]);