#include <iostream>

typedef enum {
    ONE_ARGUMENT, 
    TWO_ARGUMENTS
} State;

State checkValidity(int argc);
void checkInBuffer(std::string& str);

int main(int argc,char* argv[]) {
    std::string str;
    switch(checkValidity(argc)) {
        case ONE_ARGUMENT:
            str = argv[1];
            checkInBuffer(str);
            break;
        case TWO_ARGUMENTS:

            break;
    }
    return 0;
}

State checkValidity(int argc) {
    if(argc <= 1) {
        std::cout<<"No arguments specified\n";
        std::cout<<"grep --help for more information\n";
        exit(1);
    } else if(argc == 2) {
        return ONE_ARGUMENT;
    } else {
        return TWO_ARGUMENTS;
    }
}

void checkInBuffer(std::string& str) {
    std::string line;
    while(true) {
        getline(std::cin,line);
    }
}