#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;

    cin >> N;

    vector <long long> v(N + 1);
    vector <long long> csum(N + 2, 0);

    //v[1] * (v[2] + ... + v[N]) + v[2] * (v[3] .. v[N]) ..
    //v[1] * csum[2] + ...

    for (int i = 1; i <= N; i++)
    {
        cin >> v[i];
    }

    for (int i = N; i > 0; i--)
    {
        csum[i] = v[i] + csum[i + 1];
    }

    long long result = 0;

    for (int i = 1; i <= N; i++) 
    {
        result += v[i] * csum[i + 1];
    }

    cout << result;

}