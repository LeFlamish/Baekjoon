#include <iostream>

using namespace std;

int main() {
    int N, T; cin >> N >> T;
    int ret = 0;
    bool flag = false;
    for(int i = 0; i < T; ++i) {
        if(ret == 2 * N) flag = true;
        else if(ret == 1) flag = false;

        if(flag) ret--;
        else ret++;
    }

    cout << ret;
    return 0;
}