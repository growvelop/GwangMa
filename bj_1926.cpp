#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector <vector <int>> vec;
vector <vector <bool>> isvisit;
queue <pair<int, int>> q;
int res = 0;
int ccount = 0;

int BFS(int startD, int startI) {
	int addDepth[] = {0, 1, 0 , -1};
	int addIdx[] = {1, 0, -1, 0};	
	q.push({ startD, startI });
	isvisit[startD][startI] = true;
	int result = vec[startD][startI];

	while (!(q.empty())) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextDepth = cur.first + addDepth[i];
			int nextIdx = cur.second + addIdx[i];
			if (nextDepth >= 0 && nextIdx >= 0 && nextDepth < n && nextIdx < m && isvisit[nextDepth][nextIdx] == false) {
				if (vec[nextDepth][nextIdx] != 0) {
					isvisit[nextDepth][nextIdx] = true;
					q.push({ nextDepth, nextIdx });
					result++;
				}
			}
		}
	}
	return result;
}

int main() {
	cin >> n >> m;
	
	vec.resize(n, vector<int>(m));
	isvisit.resize(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp;
			cin >> tmp;
			vec[i][j] = tmp;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vec[i][j] == 1 && !isvisit[i][j]) {
				res = max(res, BFS(i, j));
				ccount++;
			}
		}
	}

	cout << ccount << "\n" << res;
}