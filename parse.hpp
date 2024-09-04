/**
 * parse.hpp
 * 
 * @authors Noah Nickles, Dylan Stephens
 * @date 9/ /2024
 * @info Course COP4634
 */

#ifndef _PARSE_HPP
#define _PARSE_HPP

#include <iostream>
#include <cstring>
#include "param.hpp"

class Parse {
    private:
        static constexpr const char* DELIM             = " \t";
        static constexpr const char* BACKGROUND_FLAG   = "&";
        
        static constexpr char IN_REDIRECT_FLAG  = '<';
        static constexpr char OUT_REDIRECT_FLAG = '>';

        static constexpr const char* EXIT_COMMAND = "exit";
        void handleInputRedirection(char* &token, Param &param);
        void handleOutputRedirection(char* &token, Param &param);
        void handleBackgroundProcess(char* &token, Param &param);


    public:
        Parse();
        ~Parse();
        bool parseCommand(char* command, Param& param);
};

#endif