// # µ¿Àü 1

#include <iostream>
#include <vector>

#define MAX 10001

using namespace std;

int dp[MAX] = { 0 };

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	vector<int> vecN(N);
	for (int i = 0; i < N; i++)
	{
		cin >> vecN[i];
	}

	dp[0] = 1;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = vecN[i]; j <= K; j++)
		{
			dp[j] = dp[j] + dp[j - vecN[i]];
		}
	}

	cout << dp[K];

	return 0;
}