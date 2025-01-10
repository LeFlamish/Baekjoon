#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string name;
int age, weight;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while (1) {
		cin >> name >> age >> weight;
		if (name == "#" && age == 0 && weight == 0) break;
		if (age > 17 || weight >= 80) cout << name << " Senior" << '\n';
		else cout << name << " Junior" << '\n';
	}
    return 0;
}