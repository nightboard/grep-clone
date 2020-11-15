#pragma once

typedef enum {
    PROVIDE_BUFFER,
    CHECK_FOR_FILE
} State;

State checkValidArgs(int,char *[]);
void provideBuffer(const std::string&);
void help();
void handleMeta(int,char *[]);
bool isNeedHelp(int ,char *[]);
void handleFile(const std::string&,const std::string&);
bool isColor(int,char *[]);
void printWithColor(const std::string&,const std::string&,const int&);
