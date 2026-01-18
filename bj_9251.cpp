#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string A, B;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> A >> B;

    int n = A.size();
    int m = B.size();

    vector<int> prev(m + 1, 0), cur(m + 1, 0);

    for (int i = 1; i <= n; i++) {
        cur[0] = 0;
        for (int j = 1; j <= m; j++) {
            if (A[i - 1] == B[j - 1]) cur[j] = prev[j - 1] + 1;
            else cur[j] = max(prev[j], cur[j - 1]);
        }
        prev.swap(cur);
    }

    cout << prev[m];

}
