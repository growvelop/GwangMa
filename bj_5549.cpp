#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int M, N, K;

    cin >> M >> N;

    vector<vector <int>> jsum(M + 1, vector <int>(N + 1, 0));
    vector<vector <int>> osum(M + 1, vector <int>(N + 1, 0));
    vector<vector <int>> isum(M + 1, vector <int>(N + 1, 0));

    cin >> K;

    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            char topography;

            cin >> topography;

            int J = (topography == 'J');
            int O = (topography == 'O');
            int I = (topography == 'I');

            jsum[i][j] = jsum[i - 1][j] + jsum[i][j - 1] - jsum[i - 1][j - 1] + J;
            osum[i][j] = osum[i - 1][j] + osum[i][j - 1] - osum[i - 1][j - 1] + O;
            isum[i][j] = isum[i - 1][j] + isum[i][j - 1] - isum[i - 1][j - 1] + I;
        }
    }

    for (int i = 1; i <= K; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout
            << jsum[c][d] - jsum[a - 1][d] - jsum[c][b - 1] + jsum[a - 1][b - 1] << " "
            << osum[c][d] - osum[a - 1][d] - osum[c][b - 1] + osum[a - 1][b - 1] << " "
            << isum[c][d] - isum[a - 1][d] - isum[c][b - 1] + isum[a - 1][b - 1] << "\n";
    }

}