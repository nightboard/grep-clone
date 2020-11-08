#ifndef _GLIBCXX_IOSTREAM
#include <iostream>
#endif
#include "args.h"
#include "matchAlgo.h"

State checkValidArgs(int argc) {
    if(argc == 1) {
        std::cout<<"No arguments grep --help for more information\n";
        exit(1);
    } else if(argc == 2) {
        return ONE_ARGUMENT;
    } else {
        return TWO_ARGUMENTS;
    }
}

void checkInBuffer(const std::string& str) {
    std::string line;
    while(true) {
        getline(std::cin,line);
        if(findSubString(line,str)) {
            std::cout<<line<<std::endl;
        }
    }
}