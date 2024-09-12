// # 차이를 최대로

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> vecN(N);

	for (int i = 0; i < N; i++)
	{
		cin >> vecN[i];
	}
	
	sort(vecN.begin(), vecN.end());

	int maxNum = 0;

	do
	{
		int sum = 0;

		for (int i = 0; i < vecN.size() - 1; i++)
		{
			sum += abs(vecN[i] - vecN[i + 1]);
		}
		maxNum = std::max(maxNum, sum);

	} while (next_permutation(vecN.begin(), vecN.end()));

	cout << maxNum;

	return 0;
}