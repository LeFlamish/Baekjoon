#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Node {
    int num;
    struct Node* prev;
    struct Node* next;
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    Node** node = new Node * [N + 2];
    for (int i = 0; i <= N + 1; i++) {
        node[i] = new Node;
    }
    Node*& head = node[0];
    Node*& tail = node[N + 1];
    for (int i = 1; i <= N; i++) {
        node[i]->num = i;
        node[i]->prev = node[i - 1];
        node[i]->next = node[i + 1];
    }
    head->next = node[1];
    tail->prev = node[N];

    int X, Y;
    char cmd;
    for (int i = 0; i < M; i++) {
        cin >> cmd >> X >> Y;
        node[X]->prev->next = node[X]->next;
        node[X]->next->prev = node[X]->prev;
        if (cmd == 'A') {
            node[X]->prev = node[Y]->prev;
            node[X]->next = node[Y];
            node[Y]->prev->next = node[X];
            node[Y]->prev = node[X];
        }
        else {
            node[X]->prev = node[Y];
            node[X]->next = node[Y]->next;
            node[Y]->next->prev = node[X];
            node[Y]->next = node[X];
        }
    }

    vector<int> arr;
    vector<int> minLast(N, INT_MAX);
    vector<int> location;
    int lisLength = 0;
    Node* cur = node[0];
    int i = 0;
    while ((cur = cur->next) != node[N + 1]) {
        arr.push_back(cur->num);
        i++;
        int index = lower_bound(minLast.begin(), minLast.end(), cur->num) - minLast.begin();
        minLast[index] = cur->num;
        location.push_back(index + 1);
        lisLength = max(lisLength, index + 1);
    }

    vector<int> lis(lisLength + 1);
    lis[0] = 0;
    int len = lisLength;
    for (int i = location.size() - 1; i >= 0; i--) {
        if (location[i] == len) {
            lis[len--] = arr[i];
        }
    }
    cout << N - lisLength << '\n';

    int now;
    for (int i = lisLength; i >= 1; i--) {
        now = lis[i] - 1;
        while (now > lis[i - 1]) {
            cout << "A " << now << " " << now + 1 << "\n";
            now--;
        }
    }

    for (int now = lis.back() + 1; now <= N; now++) {
        cout << "B " << now << " " << now - 1 << "\n";
    }

    for (int i = 0; i <= N + 1; i++) {
        delete node[i];
    }
    delete node;
    return 0;
}