// # 연구소
#include <iostream>
#include <vector>

#define MAX 8
#define WALL_CNT 3

using namespace std;

int N, M, cnt, maxNum;
int arr[MAX][MAX] = { 0 };

vector<pair<int, int>> direction = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
vector<pair<int, int>> vecWall, vecVirus;

void spread()
{
	int dfs[MAX][MAX] = { 0 };

	for (int i = 0; i < vecVirus.size(); i++)
	{
		int nIdx = vecVirus[i].first;
		int mIdx = vecVirus[i].second;

		dfs[nIdx][mIdx] = 2;

		DFS(nIdx, mIdx, dfs);
	}
}


void DFS(int nIdx, int mIdx, int dfs[MAX][MAX])
{
	for (int i = 0; i < direction.size(); i++)
	{
		int nextN = nIdx + direction[i].first;
		int nextM = mIdx + direction[i].second;

		if (nextN < 0 || nextN >= N || nextM < 0 || nextM >= M) continue;

		if (dfs[nextN][nextM] == 0)
		{
			cnt--;
			arr[nextN][nextM] = 2;
			DFS(nextN, nextM, arr);
		}
	}
}


void Print()
{
	cout << endl;

	// 4. 결과 출력
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	// 1. N X M 크기 영역의 데이터 삽입
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 0) vecWall.emplace_back(make_pair(i, j));
			if (arr[i][j] == 2) vecVirus.emplace_back(make_pair(i, j));
		}
	}

	// 2. 3개의 벽을 세우는 경우의 수
	int wallCnt = vecWall.size();

	for (int i = 0; i < wallCnt; i++)
	{
		for (int j = i + 1; j < wallCnt; j++)
		{
			for (int k = j + 1; k < wallCnt; k++)
			{
				arr[vecWall[i].first][vecWall[i].second] = 1;
				arr[vecWall[j].first][vecWall[j].second] = 1;
				arr[vecWall[k].first][vecWall[k].second] = 1;

				cnt = vecWall.size() - 3;

				// 3. 바이러스를 빈 영역에 퍼트리는 과정
				//for (int l = 0; l < vecVirus.size(); l++)
				//{
				//	BFS(vecVirus[i].first, vecVirus[i].second, arr);
				//}

				Print();
				cout << "Cnt : " << cnt << " | " << "Max : " << maxNum << '\n';
				maxNum = std::max(maxNum, cnt);

				arr[vecWall[i].first][vecWall[i].second] = 0;
				arr[vecWall[j].first][vecWall[j].second] = 0;
				arr[vecWall[k].first][vecWall[k].second] = 0;
			}
		}
	}

	// 3. 바이러스를 빈 영역에 퍼트리는 과정
	//for (int i = 0; i < vecVirus.size(); i++)
	//{
	//	BFS(vecVirus[i].first, vecVirus[i].second);
	//}

	//Print();

	cout << endl;
	cout << "Cnt : " << cnt << '\n';

	return 0;
}