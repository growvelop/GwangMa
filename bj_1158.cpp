#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    queue<int> q;

    for (int i = 1; i <= N; i++)
    {
        q.push(i);
    }

    cout << "<";

    while (!q.empty())
    {
        for (int i = 0; i < K - 1; i++)
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }

        cout << q.front();
        q.pop();

        if (!q.empty())
            cout << ", ";
    }
    cout << ">";
}
