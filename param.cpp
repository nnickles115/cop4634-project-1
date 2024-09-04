/**
 * param.cpp
 *  
 * Thomas Reichherzer
 * Copyright 2009 UWF - CS. All rights reserved.
 * 
 *
 */
#include "param.hpp"

using namespace std;

Param::Param() {
	inputRedirect  = NULL; 
	outputRedirect = NULL;
	background 	   = 0;
	argumentCount  = 0;
}

void Param::addArgument(char* newArgument) {
	if(newArgument == NULL) return;

	if(argumentCount < MAXARGS) {
		argumentVector[argumentCount++] = newArgument;
	}
	else {
		cerr << "Error: Too many arguments. Maximum allowed is " 
			 << MAXARGS 
			 << "\n";
	}
}

char** Param::getArguments() {
	char** args = new char*[argumentCount + 1];
	for(int i = 0; i < argumentCount; i++) {
		args[i] = argumentVector[i];
	}
	args[argumentCount] = NULL; // Add NULL terminator
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