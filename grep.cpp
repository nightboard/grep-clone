#include <iostream>
#include "src/args.h"
#include "src/matchAlgo.h"

int main(int argc,char *argv[]) {
    switch(checkValidArgs(argc,argv)) {
        case PROVIDE_BUFFER:
            provideBuffer(std::string(argv[1]));
            break;
        case CHECK_FOR_FILE:
            handleFile(std::string(argv[1]),std::string(argv[2]));
            break;
    }
    return 0;
}
