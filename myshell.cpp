#include <iostream>
#include <cstring>
#include "parse.hpp"
#include "param.hpp"

static constexpr const char* PROMPT     = "$$$ ";
static constexpr const char* DEBUG_FLAG = "-Debug";
static constexpr int MAX_COMMAND_LENGTH = 256;

bool isDebugMode(int argc, char** argv) {
    for(int i = 1; i < argc; i++) {
        if(std::strcmp(argv[i], DEBUG_FLAG) == 0) {
            return true;
        }
    }
    return false;
}

void run(bool& debug, Parse& parser) {
    while(true) {
        Param param;
        char command[MAX_COMMAND_LENGTH];

        // Prompt user and read input.
        std::cout << PROMPT;
        std::cin.getline(command, MAX_COMMAND_LENGTH);

        // Parse input. If it returns true, "exit" was entered by the user.
        bool exitProgram = parser.parseCommand(command, param);
        if(exitProgram) {
            break;
        }

        if(debug) {
            param.printParams();
        }
    }
}

int main(int argc, char** argv) {
    Parse* parser = new Parse();

    bool debug = isDebugMode(argc, argv);
    run(debug, *parser);

    delete parser;
    return 0;
}