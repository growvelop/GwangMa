#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T, K;
    string W;

    cin >> T;

    while (T--)
    {
        cin >> W >> K;

        vector <vector <int>> vec(26);
        int len = 0, maxLen = 0; int minLen = INT_MAX;
        bool find = false;
        
        for (int i = 0; i < W.size(); i++)
        {   
            vec[W[i] - 'a'].push_back(i);
            // A [0] [2] [3] [4] [6]
            // B [1] [5]
        }

        for (int i = 0; i < 26; i++)
        {
            if (vec[i].size() < K) {
                continue;
            }

            for (int j = 0; j <= vec[i].size() - K ; j++)
            {
                len = vec[i][j + K - 1] - vec[i][j] + 1;
                maxLen = max(len, maxLen);
                minLen = min(len, minLen);
                find = true;
            }
        }
        if (find)
            cout << minLen << " " << maxLen << "\n";
        else
            cout << "-1\n";
    }
}