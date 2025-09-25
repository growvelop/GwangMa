#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, d, k, c;
    int kind = 0, result = 0;

    cin >> N >> d >> k >> c;

    vector <int> sushi(N);
    vector <int> sushiCount(d + 1, 0);

    for (auto& ref : sushi) { cin >> ref; }

    for (int i = 0; i < k ; i++)
    {
        sushiCount[sushi[i]]++;
        if (sushiCount[sushi[i]] <= 1)
            kind++;
    }

    if (sushiCount[c] == 0) {
        result = kind + 1;
    }
    else {
        result = kind;
    }

    for (int i = k; i < N + k; i++)
    {
        if (i >= N - k + 1)
        {
            int tmp = i % N;

            sushiCount[sushi[i - k]]--;

            if (sushiCount[sushi[i - k]] == 0)
            {
                kind--;
            }

            if (sushiCount[sushi[tmp]] == 0)
            {
                kind++;
            }

            sushiCount[sushi[tmp]]++;
        }
        else
        {
            sushiCount[sushi[i - k]]--;

            if (sushiCount[sushi[i - k]] == 0)
            {
                kind--;
            }

            if (sushiCount[sushi[i]] == 0)
            {
                kind++;
            }

            sushiCount[sushi[i]]++;
        }
        if (sushiCount[c] == 0)
            result = max(result, kind + 1);
        else
            result = max(result, kind);
    }

    cout << result;
}