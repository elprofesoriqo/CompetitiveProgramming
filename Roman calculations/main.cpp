#include <iostream>
#include <map>
#include <string>
using namespace std;
#include <sstream>

int toInt(string& str)
{
    map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;

    int sum = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (m[str[i]] < m[str[i + 1]])
        {
            sum += m[str[i + 1]] - m[str[i]];
            i++;
            continue;
        }
        sum += m[str[i]];
    }
    return sum;
}

string toString(int number) {
    string result;

    if (number >= 1000) {
        result += string(number / 1000, 'M');
        number %= 1000;
    }
    if (number >= 900) {
        result += "CM";
        number -= 900;
    }
    if (number >= 500) {
        result += "D";
        number -= 500;
    }
    if (number >= 400) {
        result += "CD";
        number -= 400;
    }
    if (number >= 100) {
        result += string(number / 100, 'C');
        number %= 100;
    }
    if (number >= 90) {
        result += "XC";
        number -= 90;
    }
    if (number >= 50) {
        result += "L";
        number -= 50;
    }
    if (number >= 40) {
        result += "XL";
        number -= 40;
    }
    if (number >= 10) {
        result += string(number / 10, 'X');
        number %= 10;
    }
    if (number >= 9) {
        result += "IX";
        number -= 9;
    }
    if (number >= 5) {
        result += "V";
        number -= 5;
    }
    if (number >= 4) {
        result += "IV";
        number -= 4;
    }
    if (number >= 1) {
        result += string(number, 'I');
    }

    return result;
}

int main() {
    string input;

    while (getline(cin, input)) {
        string a, b;
        char op;

        stringstream ss(input);
        ss >> a >> op >> b;

        switch (op) {
            case '+':
                if (toInt(a) + toInt(b) > 3999 || toInt(a) + toInt(b) < 1) {
                    cout << "-" << endl;
                } else {
                    cout << toString(toInt(a) + toInt(b)) << endl;
                }
                break;
            case '-':
                if (toInt(a) - toInt(b) > 3999 || toInt(a) - toInt(b) < 1) {
                    cout << "-" << endl;
                } else {
                    cout << toString(toInt(a) - toInt(b)) << endl;
                }
                break;
            case '/':
                if (toInt(b) == 0 || toInt(a) / toInt(b) > 3999 || toInt(a) / toInt(b) < 1) {
                    cout << "-" << endl;
                } else {
                    cout << toString(toInt(a) / toInt(b)) << endl;
                }
                break;
            case '*':
                if (toInt(a) * toInt(b) > 3999 || toInt(a) * toInt(b) < 1) {
                    cout << "-" << endl;
                } else {
                    cout << toString(toInt(a) * toInt(b)) << endl;
                }
                break;
            default:
                cout << "-" << endl;
        }
    }
}
