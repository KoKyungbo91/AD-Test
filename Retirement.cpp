#include <iostream>

using namespace std;

int N;
int T[15];
int P[15];

int maxProfit = 0;
int profitSum = 0;

void makeSchedule(int startDay)
{
	if (startDay >= N)
	{
		if (profitSum > maxProfit)
		{
			maxProfit = profitSum;
		}		
	}

	for (int i = startDay; i < N; i++)
	{
		// ���� �� �� �ִٸ� ���� ���� ���
		if (i + T[i] < N +1)
		{
			profitSum = profitSum + P[i];
		}		
		
		makeSchedule(i + T[i]);

		// ���� �ߴٸ� ����
		if (i + T[i] < N +1)
		{
			profitSum = profitSum - P[i];
		}		
	}
}


int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> T[i];
		cin >> P[i];
	}
	
	makeSchedule(0);

	cout << maxProfit << endl;
	   
	system("pause");

	return 0;

}