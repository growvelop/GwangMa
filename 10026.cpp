#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int N;
char grid[101][101];
bool visited[101][101];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int x, int y, bool isColorBlind) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    char color = grid[x][y];

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny]) {
                if (!isColorBlind) {
                    if (grid[nx][ny] == color) {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                } else {
                    if (color == 'R' || color == 'G') {
                        if (grid[nx][ny] == 'R' || grid[nx][ny] == 'G') {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    } else {
                        if (grid[nx][ny] == color) {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    int normalCount = 0;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                bfs(i, j, false);
                normalCount++;
            }
        }
    }

    int colorBlindCount = 0;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                bfs(i, j, true);
                colorBlindCount++;
            }
        }
    }

    cout << normalCount << " " << colorBlindCount << "\n";

    return 0;
}
