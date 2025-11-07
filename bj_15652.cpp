#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, M;
vector <int> result;

void backTrack(int depth, int cur) {
	if (depth == M) {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = cur; i <= N; i++) {
		result.push_back(i);
		backTrack(depth + 1, i);
		result.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	backTrack(0, 1);
}