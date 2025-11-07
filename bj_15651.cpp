#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, M;
vector <int> result;

void backTrack(int depth) {
	if (depth == M) {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		result.push_back(i);
		backTrack(depth + 1);
		result.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	backTrack(0);
}