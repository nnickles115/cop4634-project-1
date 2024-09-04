/**
 * @file command_handler.hpp
 * @brief Declares the CommandHandler class for executing parsed commands.
 * 
 * This file provides the declaration of the CommandHandler class, which is responsible 
 * for executing commands parsed by the shell, handling input/output redirection, 
 * managing background processes, and handling the exit command.
 * 
 * @author Noah Nickles
 * @author Dylan Stephens
 * @date 9/4/2024
 * @details Course COP4634
 */

#ifndef _COMMAND_HANDLER_HPP
#define _COMMAND_HANDLER_HPP

#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

#include "param.hpp"

/**
 * @brief The CommandHandler class manages the execution of shell commands.
 * 
 * This class is responsible for executing parsed commands by forking new processes 
 * and invoking system calls like `execvp()`. 
 * It also handles input/output redirection, background execution of processes, 
 * and the "exit" command to terminate the shell session.
 */
class CommandHandler {
    private:
        // The command to terminate the shell session ("exit").
        static constexpr const char* EXIT_COMMAND = "exit";

        /**
         * @brief Handles the shell exit process.
         * 
         * This method waits for any remaining child processes to finish (reaping 
         * any background processes), then terminates the shell by calling exit().
         */
        void exitProcess();

        /**
         * @brief Redirects input from a file.
         * 
         * This method checks if an input redirection has been set via the Param object.
         * If an input redirection file is specified, it uses freopen() to redirect input 
         * from that file to stdin. 
         * If the redirection fails, it prints an error and terminates the child process.
         * 
         * @param param The Param object containing the input redirection file path.
         */
        void redirectInput(Param& param);

        /**
         * @brief Redirects output to a file.
         * 
         * This method checks if an output redirection has been set via the Param object.
         * If an output redirection file is specified, it uses freopen() to redirect output 
         * to that file from stdout. 
         * If the redirection fails, it prints an error and terminates the child process.
         * 
         * @param param The Param object containing the output redirection file path.
         */
        void redirectOutput(Param& param);

    public:
        /**
         * @brief Executes the parsed command.
         * 
         * This method forks a new process to execute the command passed via the Param object.
         * It checks for the "exit" command, handles input/output redirection, and manages 
         * background processes. 
         * The parent process either waits for the child process to complete or 
         * runs the child process in the background.
         * 
         * @param param The Param object containing the parsed command and its associated arguments.
         */
        void execute(Param& param);
};

#endif