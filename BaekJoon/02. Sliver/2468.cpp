// # 안전 영역

#include <iostream>
#include <vector>
#include <math.h>

#define MAX 100

using namespace std;

int N;
int arr[MAX][MAX] = { 0 };

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

void DFS(int y, int x, int depth, int height, int& total, bool arrB[][MAX])
{
	if (arrB[y][x] || arr[y][x] <= height) return;

	arrB[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (arrB[ny][nx] == 1 || arr[ny][nx] <= height) continue;
		if (nx >= N || nx < 0 || ny >= N || ny < 0) continue;

		DFS(ny, nx, depth + 1, height, total, arrB);
	}

	if (depth == 0) total++;
}

void go()
{
	int maxNum = 0;
	int height = 0;

	while (true)
	{
		bool arrB[MAX][MAX] = { false };
		int total = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				DFS(i, j, 0, height, total, arrB);
			}
		}

		if (total == 0) break;

		maxNum = std::max(maxNum, total);
		height++;
	}

	cout << maxNum;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	go();

	return 0;
}