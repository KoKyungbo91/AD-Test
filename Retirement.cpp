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
		// 일을 할 수 있다면 예상 수입 계산
		if (i + T[i] < N +1)
		{
			profitSum = profitSum + P[i];
		}		
		
		makeSchedule(i + T[i]);

		// 일을 했다면 원복
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