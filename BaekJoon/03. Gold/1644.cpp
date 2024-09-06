// # �Ҽ��� ������

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> vecSum;

void eratos(int N)
{
	vector<bool> vecB(N + 1);
	std::fill(vecB.begin() + 2, vecB.end(), true);

	vecSum.reserve(N);

	// �����佺�׳׽��� ü (�Ҽ� Ȯ��)
	for (int i = 2; i * i <= N; i++)
	{
		if (!vecB[i]) continue;

		for (int j = i * i; j <= N; j += i)
		{
			vecB[j] = false;
		}
	}

	// ������ ���
	long long sum = 0;
	for (int i = 0; i <= N; i++)
	{
		if (!vecB[i]) continue;
		sum += i;
		vecSum.emplace_back(sum);
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long N;
	cin >> N;

	eratos(N);

	int startPoint = 0;
	int lastPoint = lower_bound(vecSum.begin(), vecSum.end(), N) - vecSum.begin();
	int cnt = 0;

	for (int i = lastPoint; i < vecSum.size(); i++)
	{
		long long value = vecSum[i];

		for (int j = startPoint; j <= i; j++)
		{
			if (value == N) cnt++;
			if (value <= N) break;
			
			value = vecSum[i] - vecSum[j];

			startPoint++;
		}
	}

	cout << cnt;

	return 0;
}