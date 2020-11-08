#ifndef _GLIBCXX_IOSTREAM
#include <iostream>
#endif
#include <cstring>
#include "args.h"
#include "matchAlgo.h"

State checkValidArgs(int argc,char *argv[]) {
    if(argc == 1) {
        std::cout<<"No arguments grep --help for more information\n";
        exit(1);
    } 

    int argsWithoutMeta = argc;
    for(int i=0;i<argc;i++) {
        if((*(argv[0] + 0) == '-') && (*(argv[0] + 1) == '-'))
            argsWithoutMeta--;
    }

    if(argsWithoutMeta == 2)
        return ONE_ARGUMENT;
    
    if(argsWithoutMeta == 3)
        return TWO_ARGUMENTS;
}

void provideBuffer(const std::string& str) {
    std::string line;
    while(true) {
        getline(std::cin,line);
        if(findSubString(line,str)) {
            std::cout<<line<<std::endl;
        }
    }
}

void help() {

}

bool isColorOn(int argc,char *argv[]) {
    for(int i=0;i<argc;i++) {
        if(strcmp(argv[i],"--colour")) {
            return true;
        }
    }
    return false;
}