/**
 * @file myshell.cpp
 * @brief Implements a custom Linux terminal shell.
 * 
 * This program provides a basic Linux terminal shell that
 * accepts commands and processes them using a parser.
 * 
 * @author Noah Nickles
 * @author Dylan Stephens
 * @date 9/3/2024
 * @details Course COP4634
 */

#include <iostream>
#include <cstring>
#include "parse.hpp"
#include "param.hpp"

// Stores the terminal prompt chars.
static constexpr const char* PROMPT     = "$$$ ";

// Stores the format of the flag that enables debug mode.
static constexpr const char* DEBUG_FLAG = "-Debug";

// Stores the maximum char length of a single command.
static constexpr int MAX_COMMAND_LENGTH = 256;

/**
 * @brief Checks if the debug flag is present in the program arguments.
 * 
 * @param argc Number of arguments passed to the program.
 * @param argv Array of argument strings.
 * @return true if the debug flag is present, false otherwise.
 */
bool isDebugMode(int argc, char** argv) {
    for(int i = 1; i < argc; i++) {
        if(std::strcmp(argv[i], DEBUG_FLAG) == 0) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Main program loop to run the shell.
 * 
 * This function continuously prompts the user for input, 
 * parses the command using the provided parser, 
 * and executes the parsed command.
 * 
 * The loop ends when the user inputs the "exit" command.
 * 
 * If debug mode is enabled, it will print the parsed 
 * command parameters.
 * 
 * @param debug Flag to enable or disable debug mode.
 * @param parser Reference to the Parse object for command parsing.
 */
void run(bool& debug, Parse& parser) {
    // Continuously prompt until "exit" command is called.
    while(true) {
        Param param;
        char command[MAX_COMMAND_LENGTH];

        // Prompt user and read input.
        std::cout << PROMPT;
        std::cin.getline(command, MAX_COMMAND_LENGTH);

        // Holds the return value of parser.parseCommand().
        bool exitProgram = parser.parseCommand(command, param);
        if(exitProgram) break; // End loop if "exit" was called.

        // Print param info if debug is enabled.
        if(debug) {
            param.printParams();
        }
    }
}

/**
 * @brief Entry point of the shell program.
 * 
 * Initializes the parser and determines whether debug mode is active.
 * 
 * The main program loop is executed until the user exits the shell.
 * 
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line argument strings.
 * @return int Exit status code, 0 for success.
 */
int main(int argc, char** argv) {
    // Creates a new parser object.
    Parse* parser = new Parse();

    // Determines if debug mode is enabled based on program arguments.
    bool debug = isDebugMode(argc, argv);

    // Start main program loop and pass in debug and parser instance.
    run(debug, *parser);

    // Free allocated heap memory and exit program with success.
    delete parser;
    return 0;
}