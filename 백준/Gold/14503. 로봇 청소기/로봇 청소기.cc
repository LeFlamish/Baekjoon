#include <iostream>
#include <vector>

using namespace std;

// 방향: 북(0), 동(1), 남(2), 서(3)
int dx[] = {-1, 0, 1, 0}; // 북, 동, 남, 서에 대한 행 이동
int dy[] = {0, 1, 0, -1}; // 북, 동, 남, 서에 대한 열 이동

int main() {
    int n, m;
    cin >> n >> m;
    
    int r, c, d;
    cin >> r >> c >> d;
    
    vector<vector<int>> room(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> room[i][j];
        }
    }
    
    int cleaned = 0;
    
    while (true) {
        // 현재 위치 청소
        if (room[r][c] == 0) {
            room[r][c] = 2; // 청소한 위치는 2로 표시
            cleaned++;
        }
        
        bool cleaned_any = false;
        for (int i = 0; i < 4; ++i) {
            // 왼쪽 방향으로 회전
            d = (d + 3) % 4;
            int nx = r + dx[d];
            int ny = c + dy[d];
            
            // 청소하지 않은 빈 칸이 있다면 전진
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && room[nx][ny] == 0) {
                r = nx;
                c = ny;
                cleaned_any = true;
                break;
            }
        }
        
        // 청소할 곳이 없다면
        if (!cleaned_any) {
            // 뒤로 후진
            int back = (d + 2) % 4;
            int nx = r + dx[back];
            int ny = c + dy[back];
            
            // 후진할 수 있다면 후진
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && room[nx][ny] != 1) {
                r = nx;
                c = ny;
            } else {
                // 후진할 수 없으면 종료
                break;
            }
        }
    }
    
    cout << cleaned << endl;
    return 0;
}