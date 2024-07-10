#include <iostream>
#include <vector>

using namespace std;

int findPairsWithSum(const vector<int>& arr, int N, int M) {
    int left = 0;
    int right = N - 1;
    int count = 0;
    
    while (left < right) {
        int current_sum = arr[left] + arr[right];
        if (current_sum == M) {
            count++;
            left++;
            right--;
        } else if (current_sum < M) {
            left++;
        } else {
            right--;
        }
    }
    
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; t++) {
        int N, M;
        cin >> N >> M;
        
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        
        int result = findPairsWithSum(arr, N, M);
        cout << "Case #" << t << ": " << result << "\n";
    }
    
    return 0;
}