#pragma once

#include <string>
#include <iostream>

struct Arguments {
	std::string inputFilePath, outputFilePath;
	int memorySize = 30000; // 30000 bytes is the default size
	bool error = false;
};

Arguments ArgumentParser(int argc, char* argv[]);
bool isNumber(std::string str);