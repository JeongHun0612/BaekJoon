// # 1, 2, 3 ¥ı«œ±‚

#include <iostream>

#define MAX 11

using namespace std;

int dp[MAX] = { 1, 2, 4 };

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T, N;
	cin >> T;

	for (int i = 3; i < MAX; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	while (T--)
	{
		cin >> N;
		cout << dp[N - 1] << '\n';
	}

	return 0;
}