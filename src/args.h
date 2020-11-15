#pragma once

typedef enum {
    ONE_ARGUMENT,
    TWO_ARGUMENTS
} State;

State checkValidArgs(int,char *[]);
void provideBuffer(const std::string&);
void help();
void handleMeta(int,char *[]);
bool isNeedHelp(int ,char *[]);
void handleFile(const std::string&,const std::string&);
