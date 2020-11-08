#include <iostream>
#include "src/args.h"

void checkInBuffer(const std::string& str);
bool findSubString(const std::string& str,const std::string& substr);

int main(int argc,char* argv[]) {
    switch(checkValidArgs(argc)) {
        case ONE_ARGUMENT:
            checkInBuffer(std::string(argv[1]));
            break;
        case TWO_ARGUMENTS:

            break;
    }
    return 0;
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

bool findSubString(const std::string& str,const std::string& substr) {
    for(int i=0;i<=(str.length()-substr.length());i++) {
        int j,match = 0;
        for(j=0;j<substr.length();j++) {
            if(substr[j] == str[i+j])
                match++;
        }
        if(match == substr.length())
            return true;
    }
    return false;
}
