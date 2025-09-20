#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	int str = 0, ed = 1, dif = 0;

	cin >> N >> M;

	vector <int> vec(N);
	vector <int> result;

	for (auto& ref : vec) cin >> ref;

	sort(vec.begin(), vec.end());

	while (str < ed)
	{
		dif = vec[ed] - vec[str];
		if (dif < M)
		{
			if (ed != N - 1)
				ed++;
			else
				str++;
		}
		else if (dif >= M)
		{
			result.push_back(dif);
			str++;
		}
	}

	if (!result.empty()) {
		int min = *min_element(result.begin(), result.end());
		cout << min << std::endl;
}