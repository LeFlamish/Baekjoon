#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
#define SIZE 101
typedef pair<int, int> CD;
#define X first
#define Y second

int N, M, ret;
bool visited[SIZE][SIZE];
bool turnOn[SIZE][SIZE];
vector<CD> canOn[SIZE][SIZE];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

void init() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        canOn[b][a].push_back({ c, d });
    }
}

void check() {
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            if (turnOn[y][x]) cout << "1 ";
            else cout << "0 ";
        }
        cout << '\n';
    }
}

bool isArea(int x, int y) {
    if (x < 1 || x > N || y < 1 || y > N) return false;
    return true;
}

void solve() {
    queue<CD> Q;
    turnOn[1][1] = true;
    for (int i = 0; i < M; i++) {// 굳이 다돌릴 필요없음 여기서 시간초과날듯
        bool flag = true; // 변화 없으면 굳이 더 돌릴 필요가있는가... 어짜피 시작은 1,1에서 하니까
        visited[1][1] = true;
        Q.push({ 1, 1 });
        while (!Q.empty()) {
            CD cur = Q.front(); Q.pop();
            visited[cur.Y][cur.X] = true; // push 하면서 visit true로 만들어놧는데 왜 또적어놧어 없어도 되는코드
            int k = canOn[cur.Y][cur.X].size();//size()함수를 for문 조건에 넣는 습관생기면 나중에 큰일날수있음 변수 하나 만들어서 값저장하고 쓰기
            for (int j = 0; j < k; j++) {
                CD Switch = canOn[cur.Y][cur.X][j];
                turnOn[Switch.Y][Switch.X] = true;//스위치 계속냅두면 계속 똑같은과정하니까 한번 간곳은 스위치 없애버려
            }
            canOn[cur.Y][cur.X].clear();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (isArea(nx, ny) && !visited[ny][nx]) {
                    if (turnOn[ny][nx]) {
                        visited[ny][nx] = true;
                        Q.push({ nx, ny });
                        flag = false;//변화있으니까 계속 돌게 해주고
                    }
                }
            }
        }
        memset(visited, false, sizeof(visited));
        if (flag) break;
    }
}

int getScore() {
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            if (turnOn[y][x]) ret++;
        }
    }
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    init();
    solve();
    //check();
    cout << getScore();
    return 0;
}