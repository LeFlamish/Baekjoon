#include <iostream>
#include <string>

using namespace std;

int main() {

	string str1, str2, str3, str4;

	cin >> str1 >> str2 >> str3 >> str4;

	string temp1 = str1 + str2;
	string temp2 = str3 + str4;

	long long res1 = stoll(temp1);
	long long res2 = stoll(temp2);

	cout << res1 + res2;

	return 0;
}