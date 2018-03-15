#include "DoubleBasePalindromes.h"
using namespace std;


uint64_t DoubleBasePalindromes(int max_vaule_exculsive){
    uint64_t sum=0;
    for (int i=1; i<max_vaule_exculsive; i++){
        string str=to_string(i);
        bool result1= CheckIfIsPalindrome(str);
        bool result2= CheckIfIsPalindrome(ChangeToBinary(i));
        if(result1 && result2){
            sum+=i;
        }
    }
    return sum;
}

string ChangeToBinary(int number){
    string binaryNumber;
    while(number>=1){
        binaryNumber+=((number%2==0) ? "0":"1");
        number/=2;
    }
    return binaryNumber;
}

bool CheckIfIsPalindrome(std::string str){
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