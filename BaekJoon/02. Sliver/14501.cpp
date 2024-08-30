// # Επ»η
#include <iostream>
#include <vector>

#define MAX 15

using namespace std;

int N, T, P, maxNum;

vector<int> vecT(MAX);
vector<int> vecP(MAX);
vector<int> dp(MAX + 1);

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> vecT[i] >> vecP[i];
	}

	for (int i = 0; i <= N; i++)
	{
		maxNum = std::max(maxNum, dp[i]);

		if (vecT[i] + i <= N)
		{
			dp[vecT[i] + i] = std::max(dp[vecT[i] + i], maxNum + vecP[i]);
		}
	}

	cout << maxNum;

	return 0;
}