#include <iostream>

using namespace std;

int N;
int M;

int map[50][50];
int chickenCnt = 0;
int closeChickenCnt = 0;
int answer = 100000000;

struct xy
{
	int x;
	int y;
};

xy chicken[2500];


int cal_chickenDistance(xy home)
{
	int distance = 0;
	int chickenDistance = 100000000;

	for (int i = 0; i < chickenCnt; i++)
	{
		if (chicken[i].x > -1 && chicken[i].y > -1)
		{
			distance = abs(chicken[i].x - home.x) + abs(chicken[i].y - home.y);

			if (distance < chickenDistance)
			{
				chickenDistance = distance;
			}
		}				
	}

	return chickenDistance;
}

int cal_city_chickenDistance()
{
	int city_ChickenDistane = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1)
			{
				city_ChickenDistane = city_ChickenDistane + cal_chickenDistance({ j,i });
			}
		}
	}

	return city_ChickenDistane;
}

void close_Chicken(int idx)
{
	if (chickenCnt - closeChickenCnt == M)
	{
		int temp_city_chickenDistance = 0;
		temp_city_chickenDistance = cal_city_chickenDistance();

		if (answer > temp_city_chickenDistance)
		{
			answer = temp_city_chickenDistance;
		}

		return;
	}

	for (int i = idx; i < chickenCnt; i++)
	{		
		xy temp = chicken[i];

		chicken[i] = { -1, -1 };
		closeChickenCnt++;

		close_Chicken(i + 1);

		chicken[i] = temp; // ฟ๘บน
		closeChickenCnt--;
	}
}


int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];		

			if (map[i][j] == 2)
			{
				chicken[chickenCnt] = { j,i };
				chickenCnt++;
			}
		}
	}
	
	/////

	close_Chicken(0);

	cout << answer << endl;

	//system("pause");

	return 0;
}