#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector <vector<int>> vec;
vector <bool> visited;
vector<int> DFS_Result;
vector<int> BFS_Result;

int N, M, V;

void DFS(int node) {
    visited[node] = true;
    DFS_Result.push_back(node);
    for (int next : vec[node])
    {
        if (!visited[next])
        {
            DFS(next);    
        }
    }
}

void BFS(int start) {
    queue <int> q;
    q.push(start);
    visited[start] = true;
    BFS_Result.push_back(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int next : vec[cur]){
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
                BFS_Result.push_back(next);
            }
        }
    }
}

void PrintResult(vector<int> &dVec, vector<int> &bVec) {
    for (auto& ref : dVec) cout << ref << " ";
    cout << "\n";
    for (auto& ref : bVec) cout << ref << " ";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> V;

    vec.resize(N + 1);
    visited.resize(N + 1, false);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    for (int i = 1; i <= N; ++i) {
        sort(vec[i].begin(), vec[i].end());
    }

    if (V >= 1 && V <= N) {
        DFS(V);
    }

    fill(visited.begin(), visited.end(), false);

    if (V >= 1 && V <= N) {
        BFS(V);
    }

    PrintResult(DFS_Result, BFS_Result);
}