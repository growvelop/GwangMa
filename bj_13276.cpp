#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> findMaxlen(const string& p) {
    int m = p.size();
    vector<int> maxlen(m, 0);
    int j = 0;
    for (int i = 1; i < m; i++) {
        while (j > 0 && p[i] != p[j]) j = maxlen[j - 1];
        if (p[i] == p[j]) maxlen[i] = ++j;
    }
    return maxlen;
}

vector<int> kmp(string& s, string& p) {
    vector<int> res;
    int n = s.size(), m = p.size();
    if (m == 0) return res;
    vector<int> maxlen = findMaxlen(p);
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && s[i] != p[j]) j = maxlen[j - 1];
        if (s[i] == p[j]) {
            if (j == m - 1) {
                res.push_back(i - m + 1);
                j = maxlen[j];
            }
            else j++;
        }
    }
    return res;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string S, A, B;
    cin >> S >> A >> B;

    vector<int> posA = kmp(S, A);
    vector<int> posB = kmp(S, B);

    int alen = A.size();
    int blen = B.size();

    set<string> substrings;

    for (int i : posA) {
        for (int j : posB) {
            if (i <= j && i + alen <= j + blen) {
                substrings.insert(S.substr(i, j + blen - i));
            }
        }
    }

    cout << substrings.size();

}