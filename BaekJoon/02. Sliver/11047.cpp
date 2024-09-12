// # µ¿Àü 0

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	vector<int> vecCoin(N);
	for (int i = 0; i < N; i++) cin >> vecCoin[i];

	int index = N - 1;
	int total = 0;

	auto iter = lower_bound(vecCoin.begin(), vecCoin.end(), K);
	if (iter != vecCoin.end()) index = iter - vecCoin.begin();

	while (K)
	{
		int money = vecCoin[index--];
		int cnt = K / money;

		if (cnt == 0) continue;
	
		total += cnt;
		K %= money;
	}

	cout << total;

	return 0;
}