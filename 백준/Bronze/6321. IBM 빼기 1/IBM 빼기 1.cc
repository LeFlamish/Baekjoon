#include <iostream>
#include <string>
using namespace std;

int N;
string word;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> word;

        cout << "String #" << i + 1 << "\n";
        for (int j = 0; j < word.length(); j++) {
            if (word[j] == 'Z') {
                cout << 'A';
                continue;
            }
            cout << char(word[j] + 1);
        }
        cout << "\n\n";
    }

    return 0;
}