// # 1로 만들기

#include <iostream>
#include <math.h>

#define MAX 1000000

using namespace std;

int dp[MAX] = { 0 };

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 2; i <= N; i++)
	{
		dp[i] = dp[i - 1] + 1;

		if (i % 2 == 0)
		{
			dp[i] = std::min(dp[i], dp[i / 2] + 1);
		}

		if (i % 3 == 0)
		{
			dp[i] = std::min(dp[i], dp[i / 3] + 1);
		}
	}
	
	cout << dp[N];

	return 0;
}