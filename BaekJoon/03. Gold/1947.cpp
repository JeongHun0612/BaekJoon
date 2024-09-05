// # 선물 전달
#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	long long sum = 0;

	for (int i = 2; i <= N; i++)
	{
		sum = (i % 2 == 0) ? sum * i + 1 : sum * i - 1;
		sum %= 1000000000;
	}

	cout << sum;

	return 0;
}