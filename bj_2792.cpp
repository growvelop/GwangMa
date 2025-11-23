#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N;
int M;

vector<int> vec;

bool check(ll X) {
    if (X == 0) return false;

    ll required_students = 0;

    for (int count : vec) {
        required_students += (ll)(count + X - 1) / X; //보석필요학생수 누적합
    }

    return required_students <= N;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    vec.resize(M);

    int maxval = 0;

    for (int i = 0; i < M; ++i) {
        cin >> vec[i];
        maxval = max(maxval, vec[i]);
    }

    ll low = 1;
    ll high = maxval;
    ll result = maxval;

    while (low <= high) {
        ll mid = low + (high - low) / 2;

        if (check(mid)) {
            result = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << result;
}