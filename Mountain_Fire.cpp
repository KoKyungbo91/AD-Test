/*
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int map[10][10];             // �ʱ� �Է� ���� map 
int clone_map[10][10];       // ���� ���꿡 ��� �Ǵ� map (��Ÿ�� ��� ����ɰ�)
int cutting_history[10][10]; // ������ �������� Ȯ���ϱ� ���� �뵵

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int T, N, M; // �Է� �޴� ����

struct xy
{
	int x;
	int y;
};

queue<xy> Q;

xy cur, nextPos; //BFS���� ���� ��ġ�� ���� ��ġ

// �Ϲ����� BFS (clone_map���� Ȱ����)
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

// �����ִ� ������ ���� �Լ�
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

// ���� BFS�� �����ϴ� Clone_Map�� ���� (Clone�� BFS �� ������ ���� �ǹǷ�)
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

// �ʱ��� �� ��ġ�� ť�� �ִ� �Լ�
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

		// Map�� �Է� ����
		memset(map, 0, sizeof(map));

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j];
			}
		}

		// ������ �ϳ��� �Ⱥ���
		copymap();
		initQ();
		BFS();

		int maxTree = checkTree();

		// ������ 1�� ����	
		if (M >= 1)
		{
			copymap();
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					// ������ �ְ�, �� �̷��� ���ٸ� 
					if (clone_map[i][j] == 1 && cutting_history[i][j] != 1)
					{
						clone_map[i][j] = 0;       // ������ �ڸ�
						cutting_history[i][j] = 1; // ���� �ڸ����� ǥ��

						initQ();
						BFS();

						int tempTreeNum = checkTree();
						if (tempTreeNum > maxTree)
							maxTree = tempTreeNum;

						copymap(); // Clone map ����
					}
				}
			}
		}

		// ������ 2�� ����
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
						clone_map[i][j] = 0;        // ù��° ������ �ڸ�
						cutting_history[i][j] = 1;  // ���� �ڸ����� ǥ��

						for (int ii = 0; ii < N; ii++)
						{
							for (int jj = 0; jj < N; jj++)
							{
								if (clone_map[ii][jj] == 1 && cutting_history[ii][jj] != 1)
								{
									clone_map[i][j] = 0;   // ù��° ������ �ڸ� (Clone map ���� �ؼ� �ٽ� �߶���)
									clone_map[ii][jj] = 0; // �ι�° ������ �ڸ�
									cutting_history[ii][jj] = 1;  // ���� �ڸ����� ǥ��

									initQ();
									BFS();

									int tempTreeNum = checkTree();
									if (tempTreeNum > maxTree)
										maxTree = tempTreeNum;

									copymap();   // ���⼭ clone map ���� �ϱ� ������ ù��° ������ �ٽ� �߶����
								}
							}
						}
					}
					//ù��° ���� ���� ����Ŭ�� ������ �� Ŀ�� �����丮�� �ʱ�ȭ
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