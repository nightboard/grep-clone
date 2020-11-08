typedef enum {
    ONE_ARGUMENT,
    TWO_ARGUMENTS
} State;

State checkValidArgs(int argc,char *argv[]);
void provideBuffer(const std::string& str);
void help();
bool isColorOn(int,char *[]);
