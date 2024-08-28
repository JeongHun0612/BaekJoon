// # ÇÕºÐÇØ

#include <iostream>
#define MAX 200

using namespace std;

int dp[MAX + 1][MAX + 1] = { 0 };

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i <= K; i++)
	{
		dp[1][i] = i;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;
		}
	}

	cout << dp[N][K];
	
	return 0;
}