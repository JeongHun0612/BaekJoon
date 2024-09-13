// # 부분수열의 합

#include <iostream>
#include <vector>

using namespace std;

int N, S;
int cnt = 0;

void dfs(int maxDepth, int depth, int start, int& sum, const vector<int>& vecN)
{
	if (maxDepth == depth)
	{
		if (sum == S) cnt++;
		return;
	}

	for (int i = start; i < N; i++)
	{
		sum += vecN[i];
		dfs(maxDepth, depth + 1, i + 1, sum, vecN);
		sum -= vecN[i];
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> S;

	vector<int> vecN(N);
	vector<bool> vecB(N);

	for (int i = 0; i < N; i++)
	{
		cin >> vecN[i];
	}
	
	int sum = 0;
	for (int i = 1; i <= N; i++)
	{
		dfs(i, 0, 0, sum, vecN);
	}

	cout << cnt;

	return 0;
}