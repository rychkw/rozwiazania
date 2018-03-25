#include "SimpleTemplateEngine.h"

using namespace std;

namespace nets {
    View::View(std::string str) {
            pattern=str;
    }

    string View::Render(const unordered_map <string, string> &model) const {
        string pattern1 = pattern, rendered;
        regex regex1 {R"(\{\{\w+\}\})"};
        smatch matches;

        while (regex_search (pattern1, matches, regex1)) {
            for (auto match : matches) {
                string m = match.str();
                m = m.substr(2, m.length()-4); //bez klamerek
                rendered += matches.prefix().str();

                if (model.find(m) != model.end()) {
                    rendered += model.find(m)->second; //2. element mapy
                }
            }
            pattern1 = matches.suffix().str();
        }
        rendered += pattern1;
        return rendered;
    }
}