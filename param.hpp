/**
 * @file param.hpp
 * @brief Defines the Param class for handling command-line arguments and redirection.
 * 
 * This header file defines the Param class, which stores information about
 * command-line arguments, input/output redirection, and background execution
 * flags for a custom shell program.
 * 
 * @author Thomas Reichherzer
 * @remark Modified by Noah Nickles, Dylan Stephens
 * @copyright 2009 UWF - CS. All rights reserved.
 */

#ifndef _PARAM_HPP
#define _PARAM_HPP

/// @brief Maximum number of argument tokens allowed.
#define MAXARGS 32

#include <iostream>

/**
 * @brief Class to hold input data for shell commands.
 * 
 * The Param class stores information about a command's arguments, input and
 * output redirection, and whether the command should be executed in the background.
 */
class Param {
	private:
		// File name for input redirection or NULL if none is set.
		char *inputRedirect;           

		// File name for output redirection or NULL if none is set.
		char *outputRedirect;          

		// Background execution flag (0 for false, 1 for true).
		int background;              

		// Number of arguments passed to the command (similar to argc).
		int argumentCount;           

		// Array of strings containing the command's arguments.
		char *argumentVector[MAXARGS]; 
		
	public:
		/**
		 * @brief Constructs an empty Param object.
		 * 
		 * Initializes the Param object with no arguments, no input/output redirection, 
		 * and background execution set to false.
		 */
		Param();
		
		/**
		 * @brief Adds an argument string to the argument list in this object.
		 * 
		 * This function adds a pointer to a new argument string to the argument vector. 
		 * It does not create a copy of the string, so the caller is responsible for ensuring 
		 * the argument remains valid.
		 * 
		 * @param newArgument The new argument to be added to the argument list; if NULL, nothing will be added.
		 */
		void addArgument(char* newArgument);
		
		/**
		 * @brief Retrieves the list of arguments as a null-terminated array.
		 * 
		 * This function returns a dynamically allocated array of argument strings stored
		 * in the Param object. The last element in the array is NULL to mark the end, 
		 * making the size of the array one larger than the number of arguments added.
		 * 
		 * @note The caller must deallocate the memory for the returned list.
		 * 
		 * @return A null-terminated array of argument strings.
		 */
		char** getArguments();
	
		// Getter and setter functions
		
		/**
		 * @brief Sets the filename for input redirection.
		 * 
		 * @param newInputRedirect A string specifying the input redirection filename.
		 */
		void setInputRedirect(char *newInputRedirect);
		
		/**
		 * @brief Sets the filename for output redirection.
		 * 
		 * @param newOutputRedirect A string specifying the output redirection filename.
		 */
		void setOutputRedirect(char *newOutputRedirect);
		
		/**
		 * @brief Sets the background execution flag.
		 * 
		 * This flag determines whether the command should be executed in the background.
		 * 
		 * @param newBackground An integer representing background execution (1 for true, 0 for false).
		 */
		void setBackground(int newBackground);
		
		/**
		 * @brief Retrieves the filename for input redirection.
		 * 
		 * @return A string representing the input redirection filename, or NULL if not set.
		 */
		char* getInputRedirect();
		
		/**
		 * @brief Retrieves the filename for output redirection.
		 * 
		 * @return A string representing the output redirection filename, or NULL if not set.
		 */
		char* getOutputRedirect();
		
		/**
		 * @brief Retrieves the background execution flag.
		 * 
		 * @return An integer representing background execution (1 for true, 0 for false).
		 */
		int getBackground();
		
		/**
		 * @brief Prints the stored parameters to standard output.
		 * 
		 * This function prints the input/output redirection paths, the background execution flag, 
		 * the argument count, and the list of arguments to standard output for debugging purposes.
		 */
		void printParams();
};

#endif