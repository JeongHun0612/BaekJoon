// # �ִ������� �ּҰ����

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

	// �ִ� �����
	gcdVal = gcd(A, B);
	cout << gcdVal << '\n';

	// �ִ� �����
	cout << (A * B) / gcdVal << '\n';

	return 0;
}