// # 치킨 배달

#include <iostream>
#include <vector>
#include <math.h>

#define MAX_DISTANCE 10000

using namespace std;

int N, M;
int minDistance = MAX_DISTANCE;
int arr[50][50] = { 0 };

vector<pair<int, int>> vecHouse;
vector<pair<int, int>> vecChicken;

int getChickenDistance(vector<int> vecI)
{
	// 집(N) 과 모든 치킨 집을 비교하여 가장 작은 거리를 반환 후 total 변수에 합산
	int total = 0;
	for (int i = 0; i < vecHouse.size(); i++)
	{
		int min = MAX_DISTANCE;

		for (int j = 0; j < vecI.size(); j++)
		{
			int idx = vecI[j];
			min = std::min(min, abs(vecHouse[i].first - vecChicken[idx].first) + abs(vecHouse[i].second - vecChicken[idx].second));
		}

		total += min;
	}

	return total;
}

void backTracking(int depth, int start, vector<int>& vecI)
{
	if (depth == M)
	{
		minDistance = std::min(minDistance, getChickenDistance(vecI));
		return;
	}

	for (int i = start; i < vecChicken.size(); i++)
	{
		vecI[depth] = i;
		backTracking(depth + 1, i + 1, vecI);
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	// 1. 도시 정보 입력
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];

			if (arr[i][j] == 1) vecHouse.emplace_back(make_pair(i, j));
			else if (arr[i][j] == 2) vecChicken.emplace_back(make_pair(i, j));
		}
	}

	// 2. 치킨 집 탐색을 위한 BackTracking
	vector<int> vecI(M);
	backTracking(0, 0, vecI);

	// 3. 도시의 치킨 거리 출력
	cout << minDistance;

	return 0;
}