// # Ãß¿ù

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	unordered_map<string, int> car;
	vector<int> vecN(N);

	string carStr;
	int cnt = 0;
	
	for (int i = 0; i < N; i++)
	{
		cin >> carStr;
		car.insert(make_pair(carStr, i));
		vecN[i] = i;
	}

	int first = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> carStr;

		int idx = car[carStr];

		if (idx == first)
		{
			for (int j = ++first; j < N; j++)
			{
				if (vecN[j] != 0) break;
				first++;
			}
		}
		else
		{
			cnt++;
			vecN[idx] = 0;
		}
	}

	cout << cnt;

	return 0;
}