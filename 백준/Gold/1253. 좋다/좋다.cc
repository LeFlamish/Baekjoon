#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 2000;

int num[SIZE];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    sort(num, num + N);

    int count = 0;
    for (int i = 0; i < N; i++) {
        int start = 0, end = N - 1;
        while (start < end) {
            int sum = num[start] + num[end];
            if (sum < num[i]) start++;
            else if (sum > num[i]) end--;
            else {
                if (start == i) {
                    start++;
                    continue;
                }
                else if (end == i) {
                    end--;
                    continue;
                }
                count++;
                break;
            }
        }
    }

    cout << count;
    
    return 0;
}
