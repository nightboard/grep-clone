#include <iostream>

typedef enum {
    ONE_ARGUMENT, 
    TWO_ARGUMENTS
} State;

State checkValidity(int argc);

int main(int argc,char* argv[]) {
    checkValidity(argc);
    return 0;
}

State checkValidity(int argc) {
    if(argc <= 0) {
        std::cout<<"No arguments specified\n";
        std::cout<<"grep --help for more information\n";
        exit(1);
    } else if(argc == 1) {
        return ONE_ARGUMENT;
    } else {
        return TWO_ARGUMENTS;
    }
}