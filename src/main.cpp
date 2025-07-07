#include <iostream>
#include <vector>

class Interpreter {
public:
	std::string code;
	std::vector<char> data;
	int dataPointer = 0;
	int instructionPointer = 0;
	int memorySize;

	Interpreter(unsigned int memorySize) : memorySize(memorySize) {
		data = std::vector<char>(memorySize, 0);
	}

	void Run(std::string code) {
		Reset();
		this->code = code;
		while (instructionPointer != code.length()) {
			char command = code[instructionPointer];
			RunCommand(command);
			instructionPointer++;
		}
	}

	void Reset() {
		dataPointer = 0;
		instructionPointer = 0;
		data = std::vector<char>(memorySize, 0);
	}

	void RunCommand(char command) {
		int bracketCount;
		switch (command)
		{
		case '>':
			dataPointer = (dataPointer+1) % data.size();
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
};

int main() {
	Interpreter interp(64);
	std::string code = ">++++++++[<+++++++++>-]<.>++++[<+++++++>-]<+.+++++++..+++.>>++++++[<+++++++>-]<++.------------.>++++++[<+++++++++>-]<+.<.+++.------.--------.>>>++++[<++++++++>-]<+.";
	interp.Run(code);

	return 0;
}