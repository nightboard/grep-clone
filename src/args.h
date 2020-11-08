typedef enum {
    ONE_ARGUMENT,
    TWO_ARGUMENTS
} State;

State checkValidArgs(int,char *[]);
void provideBuffer(const std::string&);
void help();
bool isColorOn(int,char *[]);
void handleMeta(int,char *[]);
bool isNeedHelp(int ,char *[]);