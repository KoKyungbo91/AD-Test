#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int map[8][8];
int Copymap[8][8];
int safezoneMax = 0;
int wallcnt;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

struct xy
{
	int x;
	int y;
};

queue<xy> Q;

xy virus, curPos, nextPos;


void BFS()
{
	while (!Q.empty())
	{
		curPos = Q.front();
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			nextPos.x = curPos.x + dx[i];
			nextPos.y = curPos.y + dy[i];

			if (nextPos.x > M-1 || nextPos.y > N-1 || nextPos.x < 0 || nextPos.y < 0)
				continue;

			if (Copymap[nextPos.y][nextPos.x] == 0)
			{
				Q.push(nextPos);
				Copymap[nextPos.y][nextPos.x] = 2;
			}
		}
	}
}

void mapCopy()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			Copymap[i][j] = map[i][j];

			if (map[i][j] == 2)
			{
				Q.push({ j,i });
			}
		}
	}
}

int checkSafeZone()
{
	int safezone_cnt = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Copymap[i][j] == 0)
			{
				safezone_cnt++;
			}
		}
	}

	return safezone_cnt;
}

void makeWall(int y)
{	
	if (wallcnt == 3)
	{
		mapCopy();
		BFS();
		int safezonecnt = checkSafeZone();

		if (safezonecnt > safezoneMax)
		{
			safezoneMax = safezonecnt;
		}

		memset(Copymap, 0, sizeof(Copymap));		

		return;
	}

	for (int i = y; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0)
			{
				map[i][j] = 1;
				wallcnt++;

				makeWall(i);
				
				map[i][j] = 0; // wall을 원복 해주는것 중요.
				wallcnt--;
			}
		}
	}
}



int main()
{
	cin >> N;
	cin >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	mapCopy();
	makeWall(0);

	cout << safezoneMax << endl;
	
	system("pause");

	return 0;
}
