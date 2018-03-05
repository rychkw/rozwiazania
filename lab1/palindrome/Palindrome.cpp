//
// Created by sylwia on 05.03.18.
//

#include "Palindrome.h"

bool is_palindrome(std::string str){
    int counter=0;
    size_t length=str.length();
    for(int i=0; i<(length/2); i++){
        if(str[i]==str[length-i-1]){
            counter++;
        }
    }
    if(counter==length/2){
        return true;
    }
    else{
        return false;
    }
}
