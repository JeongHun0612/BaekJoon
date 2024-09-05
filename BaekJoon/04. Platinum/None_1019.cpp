#include <iostream>
#include <string>

using namespace std;

int arr[10] = { 0 };

void BasicFunc(int N)
{
	string str;

	for (int i = 1; i <= N; i++)
	{
		str = to_string(i);
		for (int j = 0; j < str.size(); j++)
		{
			arr[str[j] - 48]++;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	BasicFunc(N);

	int A = N / 10;
	int B = N % 10;
	for (int i = 1; i <= B; i++)
	{
		arr[i]++;
	}
	


	return 0;
}