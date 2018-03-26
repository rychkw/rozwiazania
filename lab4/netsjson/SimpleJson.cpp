#include "SimpleJson.h"

namespace nets
{
    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const
    {
        if(rodzaj==6) {
            if (mapa.find(name) != mapa.end()) {
                auto it = mapa.find(name);
                if (it != mapa.end()) {
                    return experimental::make_optional(it->second);
                }
            } else
                return {};
        }
    }
    std::string JsonValue::ToString() const
    {
        switch (rodzaj)
        {
            case 1:
            {
                if(calkowita==0) {
                    return {};
                }else{
                    std::string s = std::to_string(calkowita);
                    return s;
                }
            }
            case 2:
            {
                std::ostringstream strs1;
                strs1 << rzeczywista;
                std::string str = strs1.str();
                return str;
            }

            case 3:
            {
                if(tekst=="")
                    return {};
                string wynik="\"";
                for (int i = 0; i< tekst.length(); i++) {
                    if (tekst[i]=='\"' || tekst[i]=='\\'){
                        wynik+="\\";
                    }
                    wynik+=tekst[i];
                }
                wynik+="\"";
                return wynik;
            }

            case 4:
            {
                if(logiczna==0)
                    return "false";
                else
                    return "true";
            }

            case 5:
            {
                string wynik="[";
                for(int i=0; i< wektor.size(); i++) {
                    if (i!=0){
                        wynik+=", " ;
                    }
                    wynik=wynik+wektor[i].ToString();
                }
                wynik+="]";
                return wynik;
            }
            case 6:
            {
                string wynik="{";
                for(const auto &n:mapa)
                {
                    if(n.first=="") {
                        wynik = wynik + "" + n.first + ": " + "" + n.second.ToString() + ", ";
                    }
                    else{
                        JsonValue wyn{n.first};
                        wynik = wynik + wyn.ToString() + ": " + n.second.ToString() + ", ";
                    }
                }
                int dlugosc = wynik.length();
                string wynik_koncowy=wynik.substr(0,dlugosc-2);
                wynik_koncowy+="}";
                return wynik_koncowy;
            }
            default:
                return{};
        }
    }


    JsonValue::JsonValue(int calkowita) : calkowita(calkowita) {
        this->calkowita=calkowita;
        rodzaj=1;
    }

    JsonValue::JsonValue(double rzeczywista) : rzeczywista(rzeczywista) {
        this->rzeczywista=rzeczywista;
        rodzaj=2;
    }

    JsonValue::JsonValue(const string &tekst) : tekst(tekst) {
        this->tekst=tekst;
        rodzaj=3;
    }

    JsonValue::JsonValue(bool logiczna) : logiczna(logiczna) {
        this->logiczna=logiczna;
        rodzaj=4;
    }

    JsonValue::JsonValue(const vector<JsonValue> &wektor) : wektor(wektor) {
        this->wektor=wektor;
        rodzaj=5;
    }

    JsonValue::JsonValue(const map<string, JsonValue> &mapa) : mapa(mapa) {
        this->mapa=mapa;
        rodzaj=6;
    }

}