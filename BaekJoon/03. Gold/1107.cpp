// # ������

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<bool> vecB(10);

int isPossible(int N)
{
	int len = 0;

	if (N == 0)
	{
		if (vecB[N]) return 0;
		return 1;
	}

	while (N > 0)
	{
		len++;
		if (vecB[N % 10]) return 0;
		N /= 10;
	}

	return len;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N;
	cin >> M;

	int num;

	while (M--)
	{
		cin >> num;
		vecB[num] = true;
	}

	// 100 ���� +, - �� ����ϰ� �������� ���
	int cnt = abs(N - 100);


	// ���� N ���� ū �� �� ������ ���
	for (int i = 0; i < cnt; i++)
	{
		int len = isPossible(N + i);
		if (len > 0)
		{
			cnt = std::min(cnt, i + len);
			break;
		}
	}

	// ���� N ���� ���� �� �� ������ ���
	for (int i = 0; i < cnt; i++)
	{
		int len = isPossible(N - i);
		if (len > 0)
		{
			cnt = std::min(cnt, i + len);
			break;
		}
	}

	cout << cnt;

	return 0;
}