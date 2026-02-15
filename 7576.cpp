#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M, N;
int board[1001][1001];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N;

    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                q.push({i, j});
            }
        }
    }

    int days = 0;
    while (!q.empty()) {
        int curr_size = q.size();
        bool changed = false;

        for (int i = 0; i < curr_size; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                    if (board[nx][ny] == 0) {
                        board[nx][ny] = 1;
                        q.push({nx, ny});
                        changed = true;
                    }
                }
            }
        }
        if (changed) days++;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 0) {
                cout << -1 << "\n";
                return 0;
            }
        }
    }

    cout << days;

}
