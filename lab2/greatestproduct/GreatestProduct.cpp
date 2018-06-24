#include "GreatestProduct.h"


int GreatestProduct(const vector<int> &v, int k) {
    vector<int> wektor=v;
    unsigned long len = wektor.size();
    sort(wektor.begin(),wektor.end());
    int iloczyn_l=1;
    int iloczyn_p=1;

    if (k<2){
        return 0;
    }
    else if (k%2==0){
        for (int i=0;i<k;i++){
            iloczyn_l=iloczyn_l*wektor[i]*wektor[i+1];
            iloczyn_p=iloczyn_p*wektor[len-i-1]*wektor[len-i-2];
            i++;
        }
        return max(iloczyn_l,iloczyn_p);
    }else{
        for (int i = 0; i<k-1; i++){
            iloczyn_l=iloczyn_l*wektor[i]*wektor[i+1];
            iloczyn_p=iloczyn_p*wektor[len-i-1]*wektor[len-i-2];
            i++;
        }
        int iloczynp, iloczynm,iloczynpp,iloczynmm;
        if (k<len/2){
            int iloczyn1,iloczyn2;
            iloczynp=max(iloczyn_l,iloczyn_p);
            iloczyn1=iloczyn_l*wektor[len-1];
            iloczyn2=iloczyn_p*wektor[len-k];
            return max(iloczyn1,iloczyn2);

        }else{
            iloczynp=iloczyn_p*wektor[len-k];
            iloczynm=iloczyn_l*wektor[k+1];
            iloczynmm=iloczyn_l*wektor[len-2];
            return max(iloczynmm,iloczynp);
        }
    }
}
