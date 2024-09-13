// # 1

#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	while (!(cin >> n).eof())
	{
		long long sum = 0;
		int cnt = 0;

		while (true)
		{
			cnt++;
			sum = sum * 10 + 1;
			sum %= n;

			if (sum == 0)
			{
				cout << cnt << '\n';
				break;
			}
		}
	}

	return 0;
}