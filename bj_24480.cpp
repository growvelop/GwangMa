#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

bool visited[100001];
vector<int> vec[100001];
int result[100001];
int index[100001];
int cnt = 0;

void dfs(int R)
{
    stack<int> s;
    s.push(R);
    visited[R] = true;
    result[R] = ++cnt;
    while (!s.empty())
    {
        int v = s.top();
        if (index[v] < (int)vec[v].size())
        {
            int next = vec[v][index[v]++];
            if (!visited[next])
            {
                visited[next] = true;
                result[next] = ++cnt;
                s.push(next);
            }
        }
        else
        {
            s.pop();
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, R;
    cin >> N >> M >> R;

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
        sort(vec[i].rbegin(), vec[i].rend());

    dfs(R);

    for (int i = 1; i <= N; i++)
        cout << result[i] << '\n';

}