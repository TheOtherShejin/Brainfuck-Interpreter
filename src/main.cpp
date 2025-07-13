#include "Interpreter.h"
#include "ArgumentParser.h"
#include <fstream>

std::string GetCode(std::string filepath) {
	std::fstream file(filepath);
	std::string code;

	std::string line;
	while (std::getline(file, line)) {
		line = line.substr(0, line.find_first_of('/'));
		line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
		if (line[0] == '/' || line == "") continue;

		code += line;
	}

	return code;
}

int main(int argc, char* argv[]) {
	Arguments arguments = ArgumentParser(argc, argv);

	std::string code = GetCode(arguments.inputFilePath);

	Interpreter interpreter(arguments.memorySize);
	interpreter.Run(code);

	std::cout << "\nOutput file saved to path: " << arguments.outputFilePath << '\n';

	return 0;
}