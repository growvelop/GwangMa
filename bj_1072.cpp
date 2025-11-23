#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

ll X, Y;

bool check(ll n, ll z) {
	ll x = X + n;
	ll y = Y + n;

	if ((y * 100) / x > z) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> X >> Y;
	ll Z = (Y * 100) / X;
	if (Z >= 99) {
		cout << -1; 
		return 0;
	}

	ll low = 0;
	ll high = 2000000000;
	int result = -1;

	while (low <= high) {
		ll mid = (low + high) / 2;
		if (check(mid, Z)) {
			result = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

	cout << result;
}