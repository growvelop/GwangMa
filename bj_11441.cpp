#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;

    cin >> N;

    vector <int> A(N + 1, 0);
    vector <int> csum(N + 1, 0);

    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        csum[i] = A[i] + csum[i - 1];
    }

    cin >> M;

    for (int k = 1; k <= M; k++)
    {
        int i, j = 0;
        cin >> i >> j;
        cout << csum[j] - csum[i - 1] << "\n";
    }

}