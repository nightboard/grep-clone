#ifndef _GLIBCXX_IOSTREAM
#include <iostream>
#endif

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