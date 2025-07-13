#pragma once

#include <iostream>
#include <vector>

class Interpreter {
private:
	void RunCommand(char command);
public:
	std::string code;
	std::vector<char> data;
	int dataPointer = 0;
	int instructionPointer = 0;
	int memorySize;

	Interpreter(unsigned int memorySize);
	void Run(std::string code);
	void Reset();
};
