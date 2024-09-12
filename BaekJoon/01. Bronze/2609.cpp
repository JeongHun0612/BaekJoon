// # 최대공약수와 최소공배수

#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int gcd(int A, int B)
{
	while (A % B)
	{
		int tmp = A % B;
		A = B;
		B = tmp;
	}

	return B;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int A, B, gcdVal;
	cin >> A >> B;

	// 최대 공약수
	gcdVal = gcd(A, B);
	cout << gcdVal << '\n';

	// 최대 공배수
	cout << (A * B) / gcdVal << '\n';

	return 0;
}