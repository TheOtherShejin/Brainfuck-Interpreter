#include "ArgumentParser.h"

Arguments ArgumentParser(int argc, char* argv[]) {
	Arguments arguments;

	if (argc == 1) {
		std::cout << "[ERROR] Invalid usage. Enter input file path or type -h for help.\n";
		arguments.error = true;
		return arguments;
	}

	arguments.inputFilePath = argv[1];
	if (arguments.inputFilePath == "-h") {
		std::cout <<
			"Usage:\n"
			"	BrainfuckInterpreter.exe [input filepath | -h] [optional arguments]\n"
			"\n"
			"Optional Arguments:\n"
			"	-o [output filepath] -> Save console output to a file.\n"
			"	-m [memory size (in bytes)] -> Allocate memory for the interpreter in bytes. It is set to 30000 bytes by default.\n"
			"	-h -> Enter only -h as the input filepath to show this help menu.\n";
		arguments.error = true;
		return arguments;
	}

	for (int i = 2; i < argc; i++) {
		std::string argument = argv[i];
		if (argument == "-m") {
			if (argc == i + 1 || !isNumber(argv[i+1])) {
				std::cout << "[ERROR] Invalid usage. Enter memory size.\n";
				arguments.error = true;
				return arguments;
			}
			arguments.memorySize = std::stoi(argv[i + 1]);
			i++;
		}
		else if (argument == "-o") {
			if (argc == i + 1) {
				std::cout << "[ERROR] Invalid usage. Enter output file path.\n";
				arguments.error = true;
				return arguments;
			}
			arguments.outputFilePath = argv[i + 1];
			i++;
		}
		else {
			std::cout << "[ERROR] Invalid argument: " << argument << '\n';
			arguments.error = true;
			return arguments;
		}
	}

	return arguments;
}

bool isNumber(std::string str) {
	for (auto& letter : str) {
		if (letter < '0' || letter > '9') return false;
	}
	return true;
}