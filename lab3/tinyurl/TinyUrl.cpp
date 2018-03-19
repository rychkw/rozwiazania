#include "TinyUrl.h"


namespace tinyurl {
    unique_ptr<TinyUrlCodec> Init(){
        auto p = make_unique<TinyUrlCodec>();
        return p;
    };

    void NextHash(array<char, 6> *state){
        for (int i=(*state).size(); i-->0; ){
            (*state)[i]+=1;
            if ((*state)[i]=='9'+1){
                (*state)[i]='A';
            }
            else if ((*state)[i]=='Z'+1){
                (*state)[i]='a';
            }
            else if ((*state)[i]=='z'+1){
                (*state)[i]='0';
            }
            if ((*state)[i]!='0'){
                break;
            }
        }
    }

    string Encode(const string &url, unique_ptr<TinyUrlCodec> *codec){
        string str;
        for (auto letterInHash: codec->get()->CurrentHash){
            str+=letterInHash;
        }
        codec->get()->Mapa.emplace(str, url);
        NextHash(&codec->get()->CurrentHash);
        return str;
    }

    string Decode(const unique_ptr<TinyUrlCodec> &codec, const string &hash){
        string url;
        auto i=codec->Mapa.find(hash);
        url=i->second;
        return url;
    }
}