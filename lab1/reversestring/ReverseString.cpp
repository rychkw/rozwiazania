//
// Created by sylwia on 05.03.18.
//

#include "ReverseString.h"

std::string reverse(std::string str){
    string reversed{};
    size_t length=str.size();
    for(int i=0; i<length; i++){
        reversed+=str[length-i-1];
    }
    return reversed;    
}