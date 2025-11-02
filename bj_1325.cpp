#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector<int> rev[100001];
int cntReach[100001];
int visited[100001];

void bfs() {
    int token = 1;
    for (int i = 1; i <= N; i++) {
        queue<int> q;
        q.push(i);
        visited[i] = token;
        int c = 1;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int nx : rev[v]) {
                if (visited[nx] != token) {
                    visited[nx] = token;
                    ++c;
                    q.push(nx);
                }
            }
        }
        cntReach[i] = c;
        ++token;
    }
}

void printResult() {
    int max = 0;
    for (int i = 1; i <= N; ++i) if (cntReach[i] > max) max = cntReach[i];
    for (int i = 1; i <= N; ++i) if (cntReach[i] == max) cout << i << ' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        rev[b].push_back(a);
    }

	bfs();
    printResult();
}