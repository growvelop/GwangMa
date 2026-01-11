#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, pair<int, int>> p;
const int INF = 1e9;

int board[130][130];
int dist[130][130];
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

int solve(int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = INF;
        }
    }

    priority_queue<p, vector<p>, greater<p>> pq;

    dist[0][0] = board[0][0];
    pq.push({ dist[0][0], {0, 0} });

    while (!pq.empty()) {
        int d = pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();

        if (d > dist[y][x]) continue;

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
                int next_w = board[ny][nx];
                if (dist[ny][nx] > d + next_w) {
                    dist[ny][nx] = d + next_w;
                    pq.push({ dist[ny][nx], {ny, nx} });
                }
            }
        }
    }
    return dist[N - 1][N - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, tc = 1;
    while (true) {
        cin >> N;
        if (N == 0) break;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> board[i][j];
            }
        }

        int result = solve(N);
        cout << "Problem " << tc++ << ": " << result << "\n";
    }
}