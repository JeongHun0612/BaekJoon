// # 감시

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#define MAX 8

using namespace std;

int N, M;
int minNum = 64;
int arr[MAX][MAX] = { 0 };

vector<pair<int, int>> vecCCTV;

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };


void check(int(*tmp)[MAX], int x, int y, int dir)
{
	dir %= 4;

	while (true)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		x = nx;
		y = ny;

		if (nx < 0 || ny < 0 || nx >= N || ny >= M) break;
		if (tmp[nx][ny] == 6) break;
		if (tmp[nx][ny] != 0) continue;
		tmp[nx][ny] = -1;
	}
}

void backTracking(int size, int depth, vector<int>& vecDir)
{
	if (size == depth)
	{
		int tmp[MAX][MAX];
		copy(&arr[0][0], &arr[0][0] + MAX * MAX, &tmp[0][0]);

		for (int i = 0; i < vecDir.size(); i++)
		{
			int x = vecCCTV[i].first;
			int y = vecCCTV[i].second;

			int type = tmp[x][y];
			int direction = vecDir[i];

			// 3번. 타입별 CCTV 감시 영역 Check
			switch (type)
			{
			case 1:
				check(tmp, x, y, direction);
				break;
			case 2:
				check(tmp, x, y, direction);
				check(tmp, x, y, direction + 2);
				break;
			case 3:
				check(tmp, x, y, direction);
				check(tmp, x, y, direction + 1);
				break;
			case 4:
				check(tmp, x, y, direction);
				check(tmp, x, y, direction + 1);
				check(tmp, x, y, direction + 2);
				break;
			case 5:
				check(tmp, x, y, direction);
				check(tmp, x, y, direction + 1);
				check(tmp, x, y, direction + 2);
				check(tmp, x, y, direction + 3);
				break;
			}
		}

		// 사각 지대 크기 확인
		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (!tmp[i][j]) cnt++;
			}
		}

		minNum = std::min(minNum, cnt);

		return;
	}

	// 0 ~ 4 방향을 전부 탐색
	for (int i = 0; i < 4; i++)
	{
		vecDir[depth] = i;
		backTracking(size, depth + 1, vecDir);
	}
}


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	// 1번. N X M 크기에 배열에 데이터 입력 및 CCTV 위치 저장
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];

			// CCTV 위치 할당
			if (arr[i][j] != 0 && arr[i][j] != 6) vecCCTV.push_back({ i, j });
		}
	}

	// 2번. 모든 방향 경우의 수를 백트래킹으로 구하기
	int size = vecCCTV.size();
	vector<int> vecDir(size);
	backTracking(size, 0, vecDir);


	// 최종. 사각 지대 최소 크기 출력
	cout << minNum;

	return 0;
}