# COP 4634 Project 1 - Custom Shell
## Authors: Noah Nickles, Dylan Stephens

### Purpose
This program is a custom implementation of an OS shell program, similar to sh/bash/zsh etc. It prompts users for input and executes commands accordingly.

#### The program preforms the following operations: 
- Accepts a "-Debug" flag to see information about the parameters.
- Prompts the user for input.
- Accepts a command as a string and parses it into tokens.
- Supports input/output redirection and process backgrounding.
- Executes command by creating child processes.
- Waits for child process to finish before continuing.
- Terminates child processes properly; avoiding zombies.
- Exits the program when "exit" is entered.
- Re-prompts user after command is entered.

#### Syntax for program flags () denotes flag functionality:
- -Debug (Launch program on startup with debug mode on.)
- command > output.txt (Output redirection.)
- command < input.txt (Input redirection.)
- command & (Run process in the background.)
- exit (Terminates all child processes and exits the shell.)