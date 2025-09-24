#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    
    cin >> N;
    
    vector <int> vec(3 * N);

    for (auto& ref : vec) { cin >> ref; }

    vector <int> sumMax(3, 0);
    vector <int> sumMin(3, 0);
    
    int result = 0;

    sumMax[0] = vec[0];
    sumMax[1] = vec[1];
    sumMax[2] = vec[2];

    sumMin[0] = vec[0];
    sumMin[1] = vec[1];
    sumMin[2] = vec[2];

    for (int i = 1; i < N; i++)
    {
        // 현재 sumMax 값들을 임시 변수에 저장
        int tempMax0 = sumMax[0];
        int tempMax1 = sumMax[1];
        int tempMax2 = sumMax[2];

        // 현재 sumMin 값들을 임시 변수에 저장
        int tempMin0 = sumMin[0];
        int tempMin1 = sumMin[1];
        int tempMin2 = sumMin[2];

        sumMax[0] = max(tempMax0 + vec[3 * i], tempMax1 + vec[3 * i]);
        sumMax[1] = max({ tempMax0 + vec[3 * i + 1], tempMax1 + vec[3 * i + 1], tempMax2 + vec[3 * i + 1] });
        sumMax[2] = max(tempMax1 + vec[3 * i + 2], tempMax2 + vec[3 * i + 2]);

        sumMin[0] = min(tempMin0 + vec[3 * i], tempMin1 + vec[3 * i]);
        sumMin[1] = min({ tempMin0 + vec[3 * i + 1], tempMin1 + vec[3 * i + 1], tempMin2 + vec[3 * i + 1] });
        sumMin[2] = min(tempMin1 + vec[3 * i + 2], tempMin2 + vec[3 * i + 2]);
    }

    cout << max({ sumMax[0], sumMax[1], sumMax[2] }) << " " << min({sumMin[0], sumMin[1], sumMin[2]});

}