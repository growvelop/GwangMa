#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const int MAX = 100001;
int dist[MAX];

void bfs(int n, int k) {
    fill(dist, dist + MAX, -1);
    deque<int> dq;

    dq.push_back(n);
    dist[n] = 0;

    while (!dq.empty()) {
        int curr = dq.front();
        dq.pop_front();

        if (curr == k) return;

        if (curr * 2 < MAX && dist[curr * 2] == -1) {
            dist[curr * 2] = dist[curr];
            dq.push_front(curr * 2);
        }

        if (curr - 1 >= 0 && dist[curr - 1] == -1) {
            dist[curr - 1] = dist[curr] + 1;
            dq.push_back(curr - 1);
        }

        if (curr + 1 < MAX && dist[curr + 1] == -1) {
            dist[curr + 1] = dist[curr] + 1;
            dq.push_back(curr + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    bfs(N, K);

    cout << dist[K];

}
