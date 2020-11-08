#include <iostream>
#include "src/args.h"
#include "src/matchAlgo.h"

int main(int argc,char *argv[]) {
    switch(checkValidArgs(argc,argv)) {
        case ONE_ARGUMENT:
            provideBuffer(std::string(argv[1]));
            break;
        case TWO_ARGUMENTS:

            break;
    }
    return 0;
}
