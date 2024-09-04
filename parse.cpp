/**
 * @file parse.cpp
 * @brief Implementation of the Parse class for handling command parsing.
 * 
 * This file contains the implementation of methods in the Parse class,
 * including parsing commands, handling input/output redirection, and
 * background execution flags.
 * 
 * @author Noah Nickles
 * @author Dylan Stephens
 * @date 9/3/2024
 * @details Course COP4634
 */

#include "parse.hpp"

void Parse::parseCommand(char* command, Param& param) {
    // Tokenize the input command string using delimiters (space or tab).
    char* token = std::strtok(command, DELIM);

    // Class to handle the parsed input.
    CommandHandler handler;

    // No tokens found, return early.
    if(token == nullptr) return;

    // Process each token in the command string.
    while(token != nullptr) {
        if(token[0] == IN_REDIRECT_FLAG) {
            parseInputRedirection(token, param);
        }
        else if(token[0] == OUT_REDIRECT_FLAG) {
            parseOutputRedirection(token, param);
        }
        else if(std::strcmp(token, BACKGROUND_FLAG) == 0) {
            parseBackgroundProcess(token, param);
            break; // '&' is the last token, so stop processing.
        }
        else {
            param.addArgument(token); // Add the token as an argument.
        }
        // Continue to the next token.
        token = std::strtok(nullptr, DELIM);
    }
    // Execute the command after parsing.
    handler.execute(param);
}

void Parse::parseInputRedirection(char* &token, Param &param) {
    // Check if input redirection is combined with the filename (e.g., "<file").
    if(token != nullptr && std::strlen(token) > 1) {
        param.setInputRedirect(token + 1); // Skip the '<' character.
        return;
    }

    // Handle the case where there's a space between '<' and the filename.
    token = std::strtok(nullptr, DELIM);
    if(token != nullptr) {
        param.setInputRedirect(token); // Set input redirection file.
    }
    else {
        std::cerr << "Error: No input file specified after '<'\n";
    }
}

void Parse::parseOutputRedirection(char* &token, Param &param) {
    // Check if output redirection is combined with the filename (e.g., ">file").
    if(token != nullptr && std::strlen(token) > 1) {
        param.setOutputRedirect(token + 1); // Skip the '>' character.
        return;
    }
    
    // Handle the case where there's a space between '>' and the filename.
    token = std::strtok(nullptr, DELIM);
    if(token != nullptr) {
        param.setOutputRedirect(token); // Set output redirection file.
    }
    else {
        std::cerr << "Error: No input file specified after '>'\n";
    }
}

void Parse::parseBackgroundProcess(char* &token, Param &param) {
    // Move to the next token to ensure '&' is the last token.
    token = std::strtok(nullptr, DELIM);
    if(token == nullptr) { // '&' must be the final token.
        param.setBackground(1); // Set background execution flag to true.
    }
    else {
        std::cerr << "Error: '&' must be at the very end of the command.\n";
    }
}