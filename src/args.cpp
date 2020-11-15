#include <iostream>
#include <cstring>
#include <fstream>
#include "args.h"
#include "matchAlgo.h"
#define GREEN "\033[0;32m"
#define NONE "\033[0m"

bool colorOn = false;

State checkValidArgs(int argc,char *argv[]) {
    short meta = 0,total_args = argc;
    for(int i=0;i<argc;i++) {
        if(*(argv[i] + 0) == '-' && *(argv[i] + 1) == '-') {
            meta++;
        }
    }

    if(meta) {
        total_args -= meta;
        total_args--;
        handleMeta(argc,argv);
    }

    if(total_args == 1)
        return PROVIDE_BUFFER;

    return CHECK_FOR_FILE;
}

void provideBuffer(const std::string& str) {
    std::string line;
    while(true) {
        getline(std::cin,line);
        if(findSubString(line,str)) {
            if(!colorOn) {
                std::cout<<line<<std::endl;
            }
            else {
                int pos = line.find(str);
                printWithColor(line,str,pos);
            }
        }
    }
}

void printWithColor(const std::string& line,const std::string& pattern,const int& pos) {
    for(int i=0;i<pos;i++) {
        putchar(line[i]);
    }
    std::cout<<GREEN;
    for(int i=pos;i<(pos+pattern.length());i++) {
        putchar(line[i]);
    }
    std::cout<<NONE;
    for(int i=(pos+pattern.length());i<line.size();i++) {
        putchar(line[i]);
    }
    std::cout<<std::endl;
}

void help() {
    std::cout<<"grep --help for help\n";
    std::cout<<"grep --color for colorful output\n";
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
    if(isColor(argc,argv))
        colorOn = true;
}

bool isColor(int argc,char *argv[]) {
    for(int i=0;i<argc;i++) {
        if(!strcmp(argv[i],"--color")) {
            return true;
        }
    }
    return false;
}

void handleFile(const std::string& pattern, const std::string& filename) {
    std::ifstream inFile;
    inFile.open(filename.c_str());
    std::string line;
    while(!inFile.eof()) {
        getline(inFile, line);
        if(findSubString(line,pattern)) {
            if(!colorOn) {
                std::cout<<line<<std::endl;
            }
            else {
                int pos = line.find(pattern);
                printWithColor(line,pattern,pos);
            }
        }
    }
    inFile.close();
}
