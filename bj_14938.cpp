#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> p;
const int INF = 1e9;

int items[101];
vector<p> graph[101];

vector<int> dijkstra(int K, int N) {
    vector<int> dist(N + 1, INF);
    priority_queue<p, vector<p>, greater<p>> pq;

    dist[K] = 0;
    pq.push({ 0, K });

    while (!pq.empty()) {
        int d = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (d > dist[cur]) continue;

        for (auto& e : graph[cur]) {
            int v = e.first;
            int w = e.second;
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({ dist[v], v });
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, r;
    cin >> n >> m >> r;

    for (int i = 1; i <= n; i++) {
        cin >> items[i];
    }

    for (int i = 0; i < r; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({ v, w });
        graph[v].push_back({ u, w });
    }

    int max_items = 0;

    for (int i = 1; i <= n; i++) {
        vector<int> res = dijkstra(i, n);
        int current_sum = 0;

        for (int j = 1; j <= n; j++) {
            if (res[j] <= m) {
                current_sum += items[j];
            }
        }
        max_items = max(max_items, current_sum);
    }

    cout << max_items;
}