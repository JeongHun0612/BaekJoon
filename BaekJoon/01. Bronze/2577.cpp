// # 숫자의 개수

#include <iostream>

using namespace std;

int num[10] = { 0 };

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int A, B, C;
	cin >> A >> B >> C;

	int mult = A * B * C;

	while (mult > 0)
	{
		num[mult % 10]++;
		mult /= 10;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << num[i] << '\n';
	}

	return 0;
}