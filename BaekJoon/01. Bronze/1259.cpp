// # ÆÓ¸°µå·Ò¼ö

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(int num)
{
	string str = to_string(num);

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

	int num;
	while (cin >> num)
	{
		if (num == 0) break;
		cout << (isPalindrome(num) ? "yes" : "no") << '\n';
	}

	return 0;
}