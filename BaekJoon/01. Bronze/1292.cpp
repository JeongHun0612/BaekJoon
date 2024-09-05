// # 쉽게 푸는 문제
#include <iostream>
#include <vector>

#define MAX 1000

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> vec(MAX + 1);
	int num = 1;
	int cnt = 0;

	for (int i = 0; i <= MAX; i++)
	{
		if (cnt == num) 
		{
			num++;
			cnt = 0;
		}

		vec[i] = num;
		cnt++;
	}

	int A, B;
	int total = 0;
	cin >> A >> B;

	for (int i = A; i <= B; i++)
	{
		total += vec[i - 1];
	}

	cout << total;

	return 0;
}