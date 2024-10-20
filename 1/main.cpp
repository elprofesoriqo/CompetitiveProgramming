#include <iostream>
#include <string>
using namespace std;

int main() {
    string sourceCode;
    string line;
    string res = "";
    int il_empty = 0;

    while (getline(cin, line)) {
        if (line.empty() && il_empty > 2) {
            break;
        }
        if (line.empty()) {
            il_empty++;
        } else {
            il_empty = 0;
        }

        size_t pos = line.find("//");
        if (pos != string::npos) {
            line = line.substr(0, pos);
        }

        sourceCode += line + "\n";
    }

    int i = 0;
    while (i < sourceCode.size()) {
        if (i + 1 < sourceCode.size() && sourceCode[i] == '/' && sourceCode[i + 1] == '*') {
            bool foundEndComment = false;
            for (int j = i + 2; j < sourceCode.size(); j++) {
                if (j + 1 < sourceCode.size() && sourceCode[j] == '*' && sourceCode[j + 1] == '/') {
                    i = j + 1;
                    foundEndComment = true;
                    break;
                }
            }
            if (!foundEndComment) {
                break;
            }
        } else {
            res += sourceCode[i];
        }
        i++;
    }

    cout << res;

    return 0;
}
