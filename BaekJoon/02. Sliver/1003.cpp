// # 피보나치 함수

#include <iostream>
#include <vector>

#define MAX 40 + 1

using namespace std;

int dpZero[MAX] = {1, 0};
int dpOne[MAX] = {0, 1};

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 2; i < MAX; i++)
	{
		dpZero[i] = dpZero[i - 1] + dpZero[i - 2];
		dpOne[i] = dpOne[i - 1] + dpOne[i - 2];
	}

	int T, N;
	cin >> T;

	while (T--)
	{
		cin >> N;
		cout << dpZero[N] << " " << dpOne[N] << '\n';
	}

	return 0;
}