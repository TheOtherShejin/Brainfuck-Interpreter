#include "ArgumentParser.h"

Arguments ArgumentParser(int argc, char* argv[]) {
	Arguments arguments;

	arguments.inputFilePath = argv[1];
	for (int i = 2; i < argc; i++) {
		std::string argument = argv[i];
		if (argument == "-m") {
			arguments.memorySize = std::stoi(argv[i + 1]);
			i++;
		}
		else if (argument == "-o") {
			arguments.outputFilePath = argv[i + 1];
			i++;
		}
	}

	return arguments;
}