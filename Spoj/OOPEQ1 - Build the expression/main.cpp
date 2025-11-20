#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>

using namespace std;

long long evaluate(const string &expr) {
    long long result = 0;
    long long currentNumber = 0;
    char currentOp = '+';

    for (size_t i = 0; i < expr.size(); ++i) {
        if (isdigit(expr[i])) {
            currentNumber = currentNumber * 10 + (expr[i] - '0');
        } else {
            if (currentOp == '+') {
                result += currentNumber;
            } else if (currentOp == '-') {
                result -= currentNumber;
            }
            currentOp = expr[i];
            currentNumber = 0;
        }
    }

    if (currentOp == '+') {
        result += currentNumber;
    } else if (currentOp == '-') {
        result -= currentNumber;
    }

    return result;
}

void generateExpressions(const vector<string>& digits, string currentExpr, size_t idx, bool hasEqualSign, set<string>& results) {
    if (idx == digits.size()) {
        if (hasEqualSign) {
            size_t equalPos = currentExpr.find('=');
            if (equalPos != string::npos) {
                string left = currentExpr.substr(0, equalPos);
                string right = currentExpr.substr(equalPos + 1);

                if (evaluate(left) == evaluate(right)) {
                    results.insert(currentExpr);
                }
            }
        }
        return;
    }

    if (currentExpr.empty()) {
        generateExpressions(digits, digits[idx], idx + 1, hasEqualSign, results);  // Rozpocznij od pierwszej cyfry
    } else {
        generateExpressions(digits, currentExpr + "+" + digits[idx], idx + 1, hasEqualSign, results);
        generateExpressions(digits, currentExpr + "-" + digits[idx], idx + 1, hasEqualSign, results);
        if (!hasEqualSign) {
            generateExpressions(digits, currentExpr + "=" + digits[idx], idx + 1, true, results);
        }
    }
}

int main() {
    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        vector<string> digits;
        string digit;
        while (ss >> digit) {
            digits.push_back(digit);
        }

        set<string> results;

        generateExpressions(digits, "", 0, false, results);

        if (!results.empty()) {
            for (const auto& result : results) {
                cout << result << endl;
            }
        }
    }

    return 0;
}
