#include "Polybius.h"
int main (int argc,char* argv[])
{
    fstream fp,fp2;
    string plik1, plik2;
    string solved, message;
    if (argv[1]){
        plik1=argv[1];
        fp2.open(plik1, ios::in);
        if (fp2.good() == true){
            getline(fp2,message);
        }

    }else{
        cout<<"nie mo¿na otworzyæ pliku do odczytu";
        exit(1);
    }
    if (argv[2]){
        plik2=argv[2];
        fp.open(plik2, ios::out);
        if (fp.good() == true ){
            int czy=0;
            if (argv[3]){
                czy = atoi(argv[3]);
                if (czy==1){
                    solved=PolybiusCrypt(message);
                    fp<<solved;
                    fp.close();
                }
                else if (czy==0){
                    solved=PolybiusDecrypt(message);
                    fp<<solved;
                    fp.flush();
                    fp.close();
                }
                else{
                    exit(1);
                }
            }
        }
    }else{
        cout<<"nie mo¿na otworzyæ pliku do zapisu";
        exit(1);
    }

    fp2.close();
    return 0;
}
