#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ret;
ll A, B;

int gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
    cin >> A >> B;
    ret = gcd(A, B);
    for (int i = 0; i < ret; i++) {
        cout << 1;
    }
	return 0;
}