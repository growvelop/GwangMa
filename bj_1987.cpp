#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int R, C;
char board[20][20];
bool visited[26];
int max_dist = 0;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void dfs(int r, int c, int depth) {
    max_dist = max(max_dist, depth);

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
            int alphabet_idx = board[nr][nc] - 'A';

            if (!visited[alphabet_idx]) {
                visited[alphabet_idx] = true;
                dfs(nr, nc, depth + 1);
                visited[alphabet_idx] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }

    visited[board[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    cout << max_dist;   

}
