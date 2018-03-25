#include "SimpleTemplateEngine.h"

using namespace std;

int main() {
    nets::View view{"Hello {{name}}!"};
    unordered_map <string, string> cos = {{"name", "Brajan"}};
    cout << view.Render(cos);
    return 0;
}