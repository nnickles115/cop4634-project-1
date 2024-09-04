/**
 * parse.cpp
 * 
 * @authors Noah Nickles, Dylan Stephens
 * @date 9/ /2024
 * @info Course COP4634
 */

#include "parse.hpp"

Parse::Parse() {
}

Parse::~Parse() {
}

void Parse::handleInputRedirection(char* &token, Param &param) {
    // No delim between flag and filename.
    if(token != nullptr && std::strlen(token) > 1) {
        param.setInputRedirect(token + 1);
        return;
    }

    // Delim between flag and filename.
    token = std::strtok(nullptr, DELIM);
    if(token != nullptr) {
        param.setInputRedirect(token);
    }
    else {
        std::cerr << "Error: No input file specified after '<'\n";
    }
}

void Parse::handleOutputRedirection(char* &token, Param &param) {
    // No delim between flag and filename.
    if(token != nullptr && std::strlen(token) > 1) {
        param.setOutputRedirect(token + 1);
        return;
    }
    
    // Delim between flag and filename.
    token = std::strtok(nullptr, DELIM);
    if(token != nullptr) {
        param.setOutputRedirect(token);
    }
    else {
        std::cerr << "Error: No input file specified after '>'\n";
    }
}

void Parse::handleBackgroundProcess(char* &token, Param &param) {
    token = std::strtok(nullptr, DELIM);
    if(token == nullptr) { // Check if nullptr for final token in command
        param.setBackground(1);
    }
    else {
        std::cerr << "Error: '&' must be at the very end of the command.\n";
    }
}

bool Parse::parseCommand(char* command, Param& param) {
    char* token = std::strtok(command, DELIM);

    // No tokens to process, return early.
    if(token == nullptr) {
        return false;
    }

    // Exit command was ran, signal program to close.
    if(std::strcmp(token, EXIT_COMMAND) == 0) {
        return true;
    }

    while(token != nullptr) {
        if(token[0] == IN_REDIRECT_FLAG) {
           handleInputRedirection(token, param);
        }
        else if(token[0] == OUT_REDIRECT_FLAG) {
            handleOutputRedirection(token, param);
        }
        else if(std::strcmp(token, BACKGROUND_FLAG) == 0) {
            handleBackgroundProcess(token, param);
            break; // & is the final token, so break out early here.
        }
        else {
            param.addArgument(token);
        }

        token = std::strtok(nullptr, DELIM); // Get next token
    }
    return false;
}