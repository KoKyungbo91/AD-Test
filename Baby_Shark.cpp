#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N;
int sea[20][20];
int time[21][21];
int visit[20][20];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int shark_level = 2;
int total_time = 0;
int foodcnt = 0;

struct xy
{
	int x;
	int y;
};

xy shark, curPos, nextPos, candidate;
queue<xy> Q;

void init_time()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			time[i][j] = 0;
		}
	}
}

void init_visit()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visit[i][j] = 0;
		}
	}
}

void BFS()
{
	Q.push(shark);    // Q에 시작점을 넣는다.	
	visit[shark.y][shark.x] = 1;

	while(!Q.empty())
	{
		curPos = Q.front();
		Q.pop();

		for (int k = 0; k < 4; k++)
		{
			nextPos.x = curPos.x + dx[k];
			nextPos.y = curPos.y + dy[k];

			if (nextPos.y >= N || nextPos.x >= N || nextPos.x < 0 || nextPos.y < 0)
				continue;

			if (sea[nextPos.y][nextPos.x] <= shark_level && visit[nextPos.y][nextPos.x] != 1)
			{
				Q.push(nextPos);
				visit[nextPos.y][nextPos.x] = 1;
				time[nextPos.y][nextPos.x] = time[curPos.y][curPos.x] + 1;
			}
		}
	}
	
}

int go_to_eat()
{
	bool foodOK = false;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (sea[i][j] < shark_level && sea[i][j] != 0)
			{
				foodOK = true;

				if (time[candidate.y][candidate.x] > time[i][j])
				{
					candidate.x = j;
					candidate.y = i;
				}
				else if((time[candidate.y][candidate.x] == time[i][j]))
				{
					if (candidate.y > i)
					{
						candidate.x = j;
						candidate.y = i;
					}
					else if (candidate.y == i && candidate.x > j)
					{
						candidate.x = j;
						candidate.y = i;
					}
				}
				
			}
		}
	}

	if (foodOK == false)
	{
		cout << total_time;

		return 0;
	}
	else
	{
		foodcnt++;
		shark = candidate;
		sea[shark.y][shark.x] = 0;
		total_time = total_time + time[candidate.y][candidate.x];
		init_time();
		init_visit();

		if (foodcnt == shark_level)
		{
			shark_level++;
			foodcnt = 0;
		}
		
		return 1;
	}	
}




int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> sea[i][j];
			
			if (sea[i][j] == 9)
			{
				shark.x = j;
				shark.y = i;				
			}
		}
	}

	sea[shark.y][shark.x] = 0;
	init_time();
		
	
	candidate.x = 20;
	candidate.y = 20;
	time[candidate.x][candidate.y] = 10000;

	BFS();

	while (go_to_eat())
	{		
		BFS();

		candidate.x = 20;
		candidate.y = 20;
		time[candidate.x][candidate.y] = 1000;
		
	}		

	system("pause");

	return 0;
}

