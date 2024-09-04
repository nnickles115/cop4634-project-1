/**
 * @file command_handler.cpp
 * @brief Implementation of the CommandHandler class for executing parsed commands.
 * 
 * This file provides the implementation of the CommandHandler class, which executes 
 * commands parsed by the shell, handles input/output redirection, and manages background 
 * processes. 
 * It also handles the shell exit command and ensures that any child processes 
 * are properly terminated.
 * 
 * @author Noah Nickles
 * @author Dylan Stephens
 * @date 9/4/2024
 * @details Course COP4634
 */

#include "command_handler.hpp"

void CommandHandler::execute(Param& param) {
    // Grab argument vector from Param class and get the 0th element.
    char** args = param.getArguments();
    const char* command = args[0];

    // Handle "exit" command.
    if(std::strcmp(command, EXIT_COMMAND) == 0) {
        delete[] args;
        exitProcess();
    }

    // Fork the process to execute the command.
    pid_t pid = fork();
    if(pid == 0) { // Child process.
        // Check for input/output redirection.
        redirectInput(param);
        redirectOutput(param);

        /* 
         * Execute the command using execvp, replacing the child process.
         * If execvp fails, print an error and exit the child process.
        */
        if(execvp(command, args) == -1) {
            std::cerr << "Error: failed to execute command \'"
                      << command
                      << "\'\n";
            exit(EXIT_FAILURE);
        }
    } 
    else if(pid < 0) { // Fork failed, print error.
        std::cerr << "Error: fork failed (" 
                  << strerror(errno) 
                  << ")\n";
    }
    else { // Parent process.
        if(param.getBackground() == 1) {
            // If background flag is set, don't wait for the child process.
            std::cout << "Process running in background [PID: " 
                      << pid 
                      << "]\n";
        } 
        else {
            // Wait for the child process to complete.
            int status;
            waitpid(pid, &status, 0);
        }
    }
    delete[] args;
}

void CommandHandler::exitProcess() {
    // Wait for any remaining child processes to finish.
    int status;
    pid_t pid;
    while((pid = waitpid(-1, &status, WNOHANG)) > 0) {
        // Reap all child processes (including background ones).
        std::cout << "Reaped child process with PID: " 
                  << pid 
                  << "\n";
    }

    // Exit the shell with a success status.
    std::cout << "Exiting the shell...\n";
    exit(EXIT_SUCCESS);  // Gracefully terminate the shell.
}

void CommandHandler::redirectInput(Param& param) {
    char* inputFile = param.getInputRedirect();

    // Check if input redirection is required.
    if(inputFile != nullptr) {
        // Redirect stdin to the specified input file or exit with error.
        if(freopen(inputFile, "r", stdin) == nullptr) {
            std::cerr << "Error: failed to redirect input from \'" 
                      << inputFile
                      << "\'\n";
            exit(EXIT_FAILURE);
        }
    }
}

void CommandHandler::redirectOutput(Param& param) {
    char* outputFile = param.getOutputRedirect();

    // Check if output redirection is required.
    if(outputFile != nullptr) {
        // Redirect stdout to the specified output file or exit with error.
        if(freopen(outputFile, "w", stdout) == nullptr) {
            std::cerr << "Error: failed to redirect output to \'" 
                      << outputFile
                      << "\'\n";
            exit(EXIT_FAILURE);
        }
    }
}