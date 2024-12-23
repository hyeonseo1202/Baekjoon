#include<iostream>
using namespace std;

int main()
{
	int N, M;
	cin >> N>>M;
	int arr[50][50];
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			char num;
			cin >> num;
			arr[i][j] = num - '0';
		}
	}
	int size = 0;
	if (N >= M) { size = M; }
	else { size = N; }
	for (int n = size - 1; n >= 0; n--)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (i + n < N && j + n < M)
				{
					if (arr[i][j] == arr[i + n][j] 
						&& arr[i][j] == arr[i + n][j + n]
						&& arr[i][j] == arr[i][j + n])
					{
						//cout << i << j << endl;
						cout << (n+1) * (n+1) << endl;
						return 0;
					}
				}
			}
		}
	}

}