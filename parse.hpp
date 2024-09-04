/**
 * @file parse.hpp
 * @brief Defines the Parse class for parsing shell commands.
 * 
 * This header file defines the Parse class, which is responsible for
 * tokenizing and parsing shell commands, handling input/output redirection,
 * background process flags, and detecting the "exit" command.
 * 
 * @author Noah Nickles
 * @author Dylan Stephens
 * @date 9/3/2024
 * @details Course COP4634
 */

#ifndef _PARSE_HPP
#define _PARSE_HPP

#include <iostream>
#include <cstring>
#include "param.hpp"

/**
 * @brief Class to parse shell commands and update a Param object.
 * 
 * The Parse class provides functionality to tokenize and parse
 * shell commands. It handles input/output redirection, background
 * execution flags, and checks for the "exit" command. It updates
 * a Param object based on the parsed command.
 */
class Parse {
    private:
        // Delimiters for tokenizing the command string (space or tab).
        static constexpr const char* DELIM = " \t";

        // The flag to indicate background execution (`&`).
        static constexpr const char* BACKGROUND_FLAG = "&";

        // The character flag to indicate input redirection (`<`).
        static constexpr char IN_REDIRECT_FLAG  = '<';

        // The character flag to indicate output redirection (`>`).
        static constexpr char OUT_REDIRECT_FLAG = '>';

        // The command to terminate the shell session ("exit").
        static constexpr const char* EXIT_COMMAND = "exit";

        /**
         * @brief Handles input redirection (`<`) for the parsed command.
         * 
         * This method checks if the current token is an input redirection symbol 
         * and assigns the next token as the input file.
         * 
         * @param token The current token being processed.
         * @param param The Param object to store the input file information.
         */
        void handleInputRedirection(char* &token, Param &param);

        /**
         * @brief Handles output redirection (`>`) for the parsed command.
         * 
         * This method checks if the current token is an output redirection symbol
         * and assigns the next token as the output file.
         * 
         * @param token The current token being processed.
         * @param param The Param object to store the output file information.
         */
        void handleOutputRedirection(char* &token, Param &param);

        /**
         * @brief Handles background execution flag (`&`) for the parsed command.
         * 
         * This method checks if the current token is the background execution flag
         * and updates the Param object to indicate that the command should be
         * executed in the background.
         * 
         * @param token The current token being processed.
         * @param param The Param object to store the background execution flag.
         */
        void handleBackgroundProcess(char* &token, Param &param);


    public:
        /**
         * @brief Constructs a Parse object.
         * 
         * The constructor initializes the Parse object with no specific data.
         */
        Parse();

        /**
         * @brief Destroys the Parse object.
         * 
         * The destructor performs cleanup operations if necessary.
         */
        ~Parse();

        /**
         * @brief Parses a command string and populates the Param object.
         * 
         * This method tokenizes the provided command string, processes any input/output
         * redirection symbols, background execution flags, and detects the "exit" command.
         * 
         * It updates the Param object accordingly.
         * 
         * @param command The command string to be parsed.
         * @param param The Param object to be populated with the parsed data.
         * @return `true` if the "exit" command is detected, `false` otherwise.
         */
        bool parseCommand(char* command, Param& param);
};

#endif