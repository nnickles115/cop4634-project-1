/**
 * @file param.cpp
 * @brief Defines functions for creating and managing a parameter object.
 * 
 * This file provides an implementation of the Param class, which stores and manages
 * command-line arguments, input/output redirection, and background execution flags.
 * 
 * @author Thomas Reichherzer
 * @remark Modified by: Noah Nickles, Dylan Stephens
 * @copyright 2009 UWF - CS. All rights reserved.
 */

#include "param.hpp"

using namespace std;

// Constructs a Param object with initial default values.
Param::Param() {
	inputRedirect  = NULL; 
	outputRedirect = NULL;
	background 	   = 0;
	argumentCount  = 0;
}

// Adds a parsed argument to the argument vector.
void Param::addArgument(char* newArgument) {
	if(newArgument == NULL) return;

	if(argumentCount < MAXARGS) {
		argumentVector[argumentCount++] = newArgument;
	} else {
		cerr << "Error: Too many arguments. Maximum allowed is " 
			 << MAXARGS 
			 << "\n";
	}
}

// Retrieves the stored arguments as a null-terminated array.
char** Param::getArguments() {
	char** args = new char*[argumentCount + 1];
	for(int i = 0; i < argumentCount; i++) {
		args[i] = argumentVector[i];
	}
	args[argumentCount] = NULL; // Add null-terminator
	return args;
}

// Sets the input redirection file path.
void Param::setInputRedirect(char *newInputRedirect) {
	inputRedirect = newInputRedirect;
}

// Sets the output redirection file path.
void Param::setOutputRedirect(char *newOutputRedirect) {
	outputRedirect = newOutputRedirect;
}

// Sets whether the command should run in the background.
void Param::setBackground(int newBackground) {
	background = newBackground;
}

// Retrieves the input redirection file path.
char* Param::getInputRedirect() {
	return inputRedirect;
}

// Retrieves the output redirection file path.
char* Param::getOutputRedirect() {
	return outputRedirect;
}

// Retrieves the background execution flag.
int Param::getBackground() {
	return background;
}

// Prints the current parameters stored in the Param object.
void Param::printParams() {
	cout << "InputRedirect: [" 
	     << (inputRedirect != NULL ? inputRedirect : "NULL");

	cout << "]"
	     << endl 
		 <<	"OutputRedirect: [" 
		 << (outputRedirect != NULL ? outputRedirect : "NULL");

	cout << "]" 
	     << endl 
		 << "Background: [" 
		 << background 
		 << "]" 
		 << endl 
		 << "ArgumentCount: [" 
		 << argumentCount 
		 << "]" 
		 << endl;

	for(int i = 0; i < argumentCount; i++)
		cout << "ArgumentVector[" 
			 << i 
			 << "]: [" 
			 << argumentVector[i] 
			 << "]" 
			 << endl;
}