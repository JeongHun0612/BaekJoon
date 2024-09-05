// # Á¦°ö ¤¤¤¤ ¼ö

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long min, max;
	cin >> min >> max;

	long long sqrtMax = sqrt(max);

	long long range = max - min + 1;
	vector<bool> vecB(range);

	for (long long i = 2; i <= sqrtMax; i++)
	{
		long long sqrtVal = i * i;
		long long start = (min - 1) / sqrtVal + 1;

		for (long long j = start; j * sqrtVal <= max; j++)
		{
			if (vecB[sqrtVal * j - min]) continue;
			vecB[sqrtVal * j - min] = true;
			range--;
		}
	}

	cout << range;

	return 0;
}