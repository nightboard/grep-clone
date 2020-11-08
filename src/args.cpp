#ifndef _GLIBCXX_IOSTREAM
#include <iostream>
#endif
#include "args.h"

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