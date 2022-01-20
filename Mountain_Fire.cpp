/*
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int map[10][10];             // 초기 입력 받은 map 
int clone_map[10][10];       // 실제 연산에 사용 되는 map (불타서 계속 변경될것)
int cutting_history[10][10]; // 나무를 베었는지 확인하기 위한 용도

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int T, N, M; // 입력 받는 변수

struct xy
{
	int x;
	int y;
};

queue<xy> Q;

xy cur, nextPos; //BFS에서 현재 위치와 다음 위치

// 일반적인 BFS (clone_map에서 활동함)
void BFS()
{
	while (!Q.empty())
	{
		cur = Q.front();
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			nextPos.x = cur.x + dx[i];
			nextPos.y = cur.y + dy[i];

			if (nextPos.x < 0 || nextPos.x >= N || nextPos.y < 0 || nextPos.y >= N)
				continue;

			if (clone_map[nextPos.x][nextPos.y] == 1)
			{
				Q.push(nextPos);
				clone_map[nextPos.x][nextPos.y] = 0;
			}
		}
	}
}

// 남아있는 나무를 세는 함수
int checkTree()
{
	int treeSum = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (clone_map[i][j] == 1)
			{
				treeSum++;
			}
		}
	}
	return treeSum;
}

// 실제 BFS를 수행하는 Clone_Map을 만듬 (Clone은 BFS 돌 때마다 변경 되므로)
void copymap()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			clone_map[i][j] = map[i][j];
		}
	}	
}

// 초기의 불 위치를 큐에 넣는 함수
void initQ()
{
	while (!Q.empty())
	{
		Q.pop();
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 2)
			{
				Q.push({ i,j });
			}
		}
	}
}

int main()
{
	cin >> T;	

	for (int testcase = 0; testcase < 5; testcase++)
	{
		cin >> N >> M;

		// Map을 입력 받음
		memset(map, 0, sizeof(map));

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j];
			}
		}

		// 나무를 하나도 안벨때
		copymap();
		initQ();
		BFS();

		int maxTree = checkTree();

		// 나무를 1개 벨때	
		if (M >= 1)
		{
			copymap();
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					// 나무가 있고, 벤 이력이 없다면 
					if (clone_map[i][j] == 1 && cutting_history[i][j] != 1)
					{
						clone_map[i][j] = 0;       // 나무를 자름
						cutting_history[i][j] = 1; // 나무 자른것을 표시

						initQ();
						BFS();

						int tempTreeNum = checkTree();
						if (tempTreeNum > maxTree)
							maxTree = tempTreeNum;

						copymap(); // Clone map 복원
					}
				}
			}
		}

		// 나무를 2개 벨때
		if (M >= 2)
		{
			copymap();
			memset(cutting_history, 0, sizeof(cutting_history));

			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (clone_map[i][j] == 1 && cutting_history[i][j] != 1)
					{
						clone_map[i][j] = 0;        // 첫번째 나무를 자름
						cutting_history[i][j] = 1;  // 나무 자른것을 표시

						for (int ii = 0; ii < N; ii++)
						{
							for (int jj = 0; jj < N; jj++)
							{
								if (clone_map[ii][jj] == 1 && cutting_history[ii][jj] != 1)
								{
									clone_map[i][j] = 0;   // 첫번째 나무를 자름 (Clone map 복원 해서 다시 잘라줌)
									clone_map[ii][jj] = 0; // 두번째 나무를 자름
									cutting_history[ii][jj] = 1;  // 나무 자른것을 표시

									initQ();
									BFS();

									int tempTreeNum = checkTree();
									if (tempTreeNum > maxTree)
										maxTree = tempTreeNum;

									copymap();   // 여기서 clone map 복원 하기 때문에 첫번째 나무를 다시 잘라야함
								}
							}
						}
					}
					//첫번째 나무 제거 사이클이 끝났을 때 커팅 히스토리를 초기화
					memset(cutting_history, 0, sizeof(cutting_history));
				}
			}
		}
		cout << "#" << testcase+1 << " " << maxTree << endl;
	}
	
	system("pause");
	
	return 0;
}
*/