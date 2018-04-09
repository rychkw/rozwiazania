#include "TextPool.h"

namespace pool
{
    TextPool::TextPool(initializer_list<string> pula)
    {
        for (auto &it : pula){
            this->pula.insert(it);
        }
    }

    TextPool::TextPool(TextPool &&nowe)
    {
        swap(pula, nowe.pula);
    }

    TextPool &TextPool::operator=(TextPool &&nowe)
    {
        if (this == &nowe){
            return nowe;
        }
        pula.clear();
        swap(pula, nowe.pula);
        return *this;
    }

    size_t TextPool::StoredStringCount() const
    {
        return pula.size();
    }
    
    TextPool::~TextPool()
    {
        pula.clear();
    }

    std::experimental::string_view TextPool::Intern(const std::string &str)
    {
        for (auto i = pula.begin(); i != pula.end(); i++){
            if (*i == str){
                return str;
            }
        }
        pula.insert(str);
        return str;
    }
}