#include <iostream>
#include <vector>
using namespace std;

int node[10001];

void post(int start, int end) {
    if (start >= end) return;

    int root = node[start];
    int delim = start + 1;

    while (delim < end) {
        if (root < node[delim]) break;
        delim++;
    }

    post(start + 1, delim);
    post(delim, end);
    cout << root << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int num;
    int idx = 0;
    while (cin >> num) node[idx++] = num;
    post(0, idx);
    return 0;
}