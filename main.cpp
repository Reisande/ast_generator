#include <iostream>
#include <string>



class AST {
private:
	struct Node {
		std::string value;
		Node **children;
	};
	Node *head;
		

public:
	AST() {
		head = nullptr;
	}
	
	
};

std::pair<bool, AST *> parse(std::string fileName) {
	std::pair<bool, AST *> returnPair(false, nullptr);

	return returnPair;
}

std::string drawFile(AST *ast) {

	return "";
}

// simple ast generator
// takes an input of a file name of a scheme file, and generates an output
// ast in the form of an ascii tree through recursive descent

// doesn't actually evaluate the code, just parses it to generate the ast for
// pedagogical purposes

// Also, I would like to expand this into a REPL like command line
// utility, where you can add multiple commands incrementally and ahve direct
// output to the command line
int main(int argc, char **argv) {

	std::cout << "Welcome to the my AST generator. Type 'h' for help\n";
	while(true) {
		std::string fileInput;

		std::cin >> fileInput;

		if(fileInput == "h") {
			std::cout << "Enter 'q' to exit the program\n"
								<< "Enter a fully qualified filename(e.g. /home/Documents/...)"
								<< "with the ending \".sc\" to generate an abstract syntax tree"
							  << "of the input file";
		}
		else if(fileInput == "q") {
			break;
		}
		else {
			std::pair<bool, AST *> validFile = parse(fileInput);

			if(validFile.first) {
				std::string returnFile = drawFile(validFile.second);

				if(returnFile != "") {
					std::cout << "The AST output has been generated in: " << returnFile << std::endl;
				}
				else {
					std::cout << "Some error has occurred in drawing the generated AST\n";
				}
			}
			else {
				std::cout << "Some error has occurred during parsing the input file\n";
			}
		}
	}

	return 0;
}
