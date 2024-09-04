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

Param::Param() {
	inputRedirect  = nullptr; 
	outputRedirect = nullptr;
	background 	   = 0;
	argumentCount  = 0;
}

void Param::addArgument(char* newArgument) {
	// Return early if argument is null.
	if(newArgument == nullptr) return;

	// Ensure args aren't more than MAXARGS.
	if(argumentCount < MAXARGS) {
		/*
		 * Increment argumentCount and add associated
		 * arg at the argumentVector's argumentCount element.
		*/
		argumentVector[argumentCount++] = newArgument;
	} 
	else {
		cerr << "Error: Too many arguments. Maximum allowed is " 
			 << MAXARGS 
			 << "\n";
	}
}

char** Param::getArguments() {
	// Create arg array with argumentCount + 1 for null-terminator.
	char** args = new char*[argumentCount + 1];

	// Copy arguments from argumentVector[] into args[].
	for(int i = 0; i < argumentCount; i++) {
		args[i] = argumentVector[i];
	}

	// Append null-terminator and return array.
	args[argumentCount] = nullptr;
	return args;
}

void Param::setInputRedirect(char *newInputRedirect) {
	inputRedirect = newInputRedirect;
}

void Param::setOutputRedirect(char *newOutputRedirect) {
	outputRedirect = newOutputRedirect;
}

void Param::setBackground(int newBackground) {
	background = newBackground;
}

char* Param::getInputRedirect() {
	return inputRedirect;
}

char* Param::getOutputRedirect() {
	return outputRedirect;
}

int Param::getBackground() {
	return background;
}

void Param::printParams() {
	cout << "InputRedirect: [" 
	     << (inputRedirect != nullptr ? inputRedirect : "NULL");

	cout << "]"
	     << endl
		 <<	"OutputRedirect: [" 
		 << (outputRedirect != nullptr ? outputRedirect : "NULL");

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