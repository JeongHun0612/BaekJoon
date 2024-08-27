// # ∞ÒµÂπŸ»Â¿« √ﬂ√¯

#include <iostream>
#include <vector>

using namespace std;

void Eratos(vector<bool>& vecPrime)
{
	for (int i = 2; i < vecPrime.size(); i++)
	{
		vecPrime[i] = true;
	}

	for (int i = 2; i * i < vecPrime.size(); i++)
	{
		if (!vecPrime[i]) continue;

		for (int j = i * i; j < vecPrime.size(); j += i)
		{
			vecPrime[j] = false;
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<bool> vecPrime(10001);
	Eratos(vecPrime);

	int T;
	cin >> T;

	int N;
	while (T--)
	{
		cin >> N;

		for (int i = N / 2; i >= 2; i--)
		{
			if (vecPrime[i] && vecPrime[N - i])
			{
				cout << i << " " << N - i << '\n';
				break;
			}
		}
	}

	return 0;
}