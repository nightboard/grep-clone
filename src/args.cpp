#include <iostream>
#include <cstring>
#include <fstream>
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

    handleMeta(argc,argv);

    if(argsWithoutMeta == 2)
        return ONE_ARGUMENT;

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
    std::cout<<"grep --help for help\n";
    std::cout<<"grep [string to match] [filename]\n";
    exit(0);
}

bool isNeedHelp(int argc,char *argv[]) {
    for(int i=0;i<argc;i++) {
        if(!strcmp(argv[i],"--help")) {
            return true;
        }
    }
    return false;
}

void handleMeta(int argc,char *argv[]) {
    if(isNeedHelp(argc,argv))
        help();
}

void handleFile(const std::string& pattern, const std::string& filename) {
    std::ifstream inFile;
    inFile.open(filename.c_str());
    std::string line;
    while(!inFile.eof()) {
        getline(inFile, line);
        if(findSubString(line,pattern)) {
            std::cout<<line<<std::endl;
        }
    }
    inFile.close();
}
