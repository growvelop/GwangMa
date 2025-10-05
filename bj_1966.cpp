#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        int N, M;
        cin >> N >> M;

        queue<pair<int, int>> q; // (priority, index)
        vector<int> priorities(N);
        int cnt = 0;

        for (int i = 0; i < N; i++)
        {
            cin >> priorities[i];
            q.push({ priorities[i], i });
        }

        while (!q.empty())
        {
            int nowPriority = q.front().first;
            int nowIndex = q.front().second;
            q.pop();

            bool hasHigher = false;

            for (int i = 0; i < N; i++)
            {
                if (priorities[i] > nowPriority)
                {
                    hasHigher = true;
                    break;
                }
            }

            if (hasHigher)
            {
                q.push({ nowPriority, nowIndex });
            }
            else
            {
                cnt++;
                priorities[nowIndex] = -1;

                if (nowIndex == M)
                {
                    cout << cnt << '\n';
                    break;
                }
            }
        }
    }
}
