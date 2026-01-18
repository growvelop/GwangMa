#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    vector<int> dp(k + 1, 100001);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        int coin = coins[i];
        for (int j = coin; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - coin] + 1);
        }
    }

    if (dp[k] == 100001) {
        cout << -1;
    } else {
        cout << dp[k];
    }
}
