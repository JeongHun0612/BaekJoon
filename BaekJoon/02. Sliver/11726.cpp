// # 2xn ≈∏¿œ∏µ

#include <iostream>

#define MAX 1001

using namespace std;

long long dp[MAX] = { 0 };

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= N; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}

	cout << dp[N];

	return 0;
}