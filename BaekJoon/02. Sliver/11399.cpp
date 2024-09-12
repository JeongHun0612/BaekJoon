// # ATM

#include <iostream>
#include <vector>
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

	int total = 0;
	int sum = 0;

	for (int data : vecN)
	{
		sum += data;
		total += sum;
	}

	cout << total;

	return 0;
}