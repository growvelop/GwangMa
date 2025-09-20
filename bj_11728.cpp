#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	int tmpA = 0, tmpB = 0;

	cin >> N >> M;

	vector <int> A(N);
	vector <int> B(M);

	//for (int i = 0; i < N; i++) cin >> A[i];
	for (auto& ref : A) cin >> ref;
	for (auto& ref : B) cin >> ref;

	while (tmpA < N && tmpB < M)
	{
		if (A[tmpA] < B[tmpB])
		{
			cout << A[tmpA] << " ";
			tmpA++;
		}
		else if (A[tmpA] > B[tmpB])
		{
			cout << B[tmpB] << " ";
			tmpB++;
		}
		else
		{
			cout << A[tmpA] << " " << B[tmpB] << " ";
			tmpA++;
			tmpB++;
		}
	}

	for (int i = tmpB; i < M; i++)
		cout << B[i] << " ";

	for (int i = tmpA; i < N; i++)
		cout << A[i] << " ";
}