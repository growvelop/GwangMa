#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> p;
const int INF = 1e9;
vector<p> graph[10001];

vector<int> dijkstra(int start, int D) {
    vector<int> dist(D + 1, INF);
    priority_queue<p, vector<p>, greater<p>> pq;

    dist[start] = 0;
    pq.push({ 0, start });

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

    int N, D;
    cin >> N >> D;

    for (int i = 0; i < D; ++i) {
        graph[i].push_back({ i + 1, 1 });
    }

    int u, v, w;
    for (int i = 0; i < N; ++i) {
        cin >> u >> v >> w;
        if (v <= D) {
            graph[u].push_back({ v, w });
        }
    }

    vector<int> result_dist = dijkstra(0, D);
    cout << result_dist[D];

}