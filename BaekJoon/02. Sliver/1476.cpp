// # 날짜 계산

#include <iostream>

const int maxE = 15;
const int maxS = 28;
const int maxM = 19;

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int E, S, M;
	cin >> E >> S >> M;

	int valE = 1, valS = 1, valM = 1, year = 0;

	while (++year)
	{
		if (valE == E && valS == S && valM == M) break;

		valE++; valS++; valM++;

		if (valE > maxE) valE = 1;
		if (valS > maxS) valS = 1;
		if (valM > maxM) valM = 1;
	}

	cout << year;

	return 0;
}