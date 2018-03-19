#ifndef JIMP_EXERCISES_TINYURL_H
#define JIMP_EXERCISES_TINYURL_H

#include <iostream>
#include <array>
#include <memory>
#include <map>

using namespace std;

namespace tinyurl {
    typedef struct TinyUrlCodec {
        array<char, 6> CurrentHash;
        map <string, string> Mapa;
    } TinyUrlCodec;

    std::unique_ptr<TinyUrlCodec> Init();
    void NextHash(std::array<char, 6> *state);
    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec);
    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash);
}


#endif //JIMP_EXERCISES_TINYURL_H
