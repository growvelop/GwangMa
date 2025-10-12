#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;

    cin >> T;

    vector <int> zcnt(41);
    vector <int> ocnt(41);

    zcnt[0] = 1, zcnt[1] = 0;
    ocnt[0] = 0, ocnt[1] = 1;

    for (int i = 2; i <= 40; i++){
        zcnt[i] = zcnt[i - 1] + zcnt[i - 2];
        ocnt[i] = ocnt[i - 1] + ocnt[i - 2];
    }

    while (T--){
        int N;
        cin >> N;
        cout << zcnt[N] << " " << ocnt[N] << '\n';
    }
}