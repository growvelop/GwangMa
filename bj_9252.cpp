#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    int len1 = s1.length();
    int len2 = s2.length();

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[len1][len2] << "\n";

    if (dp[len1][len2] > 0) {
        string result = "";
        int i = len1;
        int j = len2;

        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                result += s1[i - 1];
                i--;
                j--;
            }
            else {
                if (dp[i - 1][j] >= dp[i][j - 1]) {
                    i--;
                }
                else {
                    j--;
                }
            }
        }
        reverse(result.begin(), result.end());
        cout << result;
    }
}