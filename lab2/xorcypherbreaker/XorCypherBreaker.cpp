#include "XorCypherBreaker.h"

string XorCypherBreaker(const vector<char> &cryptogram, int key_length, const vector<string> &dictionary) {
    string tmpKey="...", mainKey="";
    int maxCounter=-10;

    for (char i='a'; i<='z'; i++) {
        for (char j='a'; j<='z'; j++) {
            for (char k='a'; k<='z'; k++) {
                tmpKey[0]=i;
                tmpKey[1]=j;
                tmpKey[2]=k;
                
                int counter=0, iter=0;
                string str="";

                for (int i=0; i<cryptogram.size(); i++){
                    char letter=(char)(tmpKey[iter%key_length] xor cryptogram[i]);
                    if ((letter>='a') && (letter<='z')) {
                        str+=letter;
                    }
                    else {
                        if (str.size()>=3) {
                            transform(str.begin(), str.end(), str.begin(), ::tolower);
                            if (find(dictionary.begin(), dictionary.end(), str)!=dictionary.end()) {
                                counter++;
                            }
                        }
                        str="";
                    }
                    iter++;
                }
                if (counter>=maxCounter) {
                    maxCounter=counter;
                    mainKey=tmpKey;
                }
            }
        }
    }
    return mainKey;
}