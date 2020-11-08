typedef enum {
    ONE_ARGUMENT,
    TWO_ARGUMENTS
} State;

State checkValidArgs(int argc);
void checkInBuffer(const std::string& str);