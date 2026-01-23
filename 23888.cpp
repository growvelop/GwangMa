#include <iostream>
#include <numeric>

using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long a, d;
    cin >> a >> d;

    int q;
    cin >> q;

    while (q--) {
        int type;
        long long l, r;
        cin >> type >> l >> r;

        long long al = a + (l - 1) * d;
        long long ar = a + (r - 1) * d;

        if (type == 1) {
            long long n = r - l + 1;
            long long sum = n * (al + ar) / 2;
            cout << sum << "\n";
        }
        else if (type == 2) {
            if (l == r) {
                cout << al << "\n";
            }
            else {
                cout << gcd(al, d) << "\n";
            }
        }
    }
}
