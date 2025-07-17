#include "Interpreter.h"

Interpreter::Interpreter(unsigned int memorySize) : memorySize(memorySize) {
	data = std::vector<char>(memorySize, 0);
}

void Interpreter::Run(std::string code) {
	Reset();
	this->code = code;
	while (instructionPointer != code.length()) {
		char command = code[instructionPointer];
		RunCommand(command);
		instructionPointer++;
	}
}

void Interpreter::Reset() {
	dataPointer = 0;
	instructionPointer = 0;
	data = std::vector<char>(memorySize, 0);
}

void Interpreter::RunCommand(char command) {
	int bracketCount;
	switch (command) {
	case '>':
		dataPointer = (dataPointer + 1) % data.size();
		break;
	case '<':
		dataPointer = (dataPointer - 1) % data.size();
		break;
	case '+':
		data[dataPointer]++;
		break;
	case '-':
		data[dataPointer]--;
		break;
	case '.':
		logHistory += char(data[dataPointer]);
		std::cout << char(data[dataPointer]);
		break;
	case ',':
		std::cout << "\n>>> ";
		int input;
		std::cin >> input;
		data[dataPointer] = input;
		break;
	case '[':
		if (data[dataPointer] != 0) break;
		bracketCount = 1;
		while (bracketCount != 0) {
			instructionPointer++;
			char command = code[instructionPointer];
			if (command == '[') bracketCount++;
			else if (command == ']') bracketCount--;
		}
		break;
	case ']':
		if (data[dataPointer] == 0) break;
		bracketCount = -1;
		while (bracketCount != 0) {
			instructionPointer--;
			char command = code[instructionPointer];
			if (command == '[') bracketCount++;
			else if (command == ']') bracketCount--;
		}
		break;
	}
}