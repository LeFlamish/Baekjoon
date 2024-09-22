#include <iostream>
#include <string>
using namespace std;

int main() {
    string binary;
    cin >> binary;

    while (binary.size() % 3 != 0) {
        binary = '0' + binary;
    }

    string result = "";
    for (size_t i = 0; i < binary.size(); i += 3) {
        string part = binary.substr(i, 3);
        int octalDigit = (part[0] - '0') * 4 + (part[1] - '0') * 2 + (part[2] - '0') * 1;
        result += to_string(octalDigit);
    }

    cout << result;
    return 0;
}