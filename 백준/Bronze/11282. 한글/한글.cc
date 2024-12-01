#include <iostream>
using namespace std;

string unicodeToUTF8(int unicode) {
	string utf8_string;

	utf8_string += (0xE0 | (unicode >> 12));
	utf8_string += (0x80 | ((unicode >> 6) & 0x3F));
	utf8_string += (0x80 | (unicode & 0x3F));

	return utf8_string;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	cout << unicodeToUTF8(N + 44032 - 1);
	return 0;
}