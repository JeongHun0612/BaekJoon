// # 소수 & 팰린드롬

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define MAX 1003002

using namespace std;

bool isPalindrome(int num)
{
	const string str = move(to_string(num));

	for (int i = 0; i < str.length() / 2; i++)
	{
		if (str[i] != str[str.length() - 1 - i]) return false;
	}

	return true;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<bool> vecB(MAX);
	vector<int> vecI;

	for (int i = 2; i < MAX; i++)
	{
		if (vecB[i]) continue;

		if (isPalindrome(i))
		{
			vecI.emplace_back(i);
		}

		for (int j = i * 2; j < MAX; j += i)
		{
			vecB[j] = true;
		}
	}

	int N;
	cin >> N;

	cout << *(lower_bound(vecI.begin(), vecI.end(), N)) << '\n';

	return 0;
}