// # 다리 놓기

#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, M;

	cin >> T;
	while (T--)
	{
		cin >> N >> M;

		int result = 1;

		for (int i = 0; i < N; i++)
		{
			result *= M - i;
			result /= i + 1;
		}

		cout << result << '\n';
	}

	return 0;
}