// # 뱀

#include <iostream>
#include <queue>
#include <vector>

#define MAX 102

using namespace std;

int arr[MAX][MAX];

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	// N : 보드의 크기
	// K : 사과의 개수
	int N, K, L;
	int cnt = 0;

	cin >> N;
	cin >> K;

	// 사과 위치 저장
	while (K--)
	{
		int col, row;
		cin >> col >> row;
		arr[row][col] = 2;
	}

	cin >> L;

	pair<int, int> headPos = make_pair(1, 1);
	vector<pair<int, int>> pos;
	pos.reserve(100);
	pos.push_back(headPos);

	int distance;
	char direction;
	while (L--)
	{
		cin >> distance >> direction;

		while (distance--)
		{
			cnt++;


		}
	}

	return 0;
}