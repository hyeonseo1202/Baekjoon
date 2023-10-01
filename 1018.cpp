#include<iostream>
using namespace std;

int confirm(int** arr,int a, int b) {
	int sum1 = 0,sum2 = 0;
	for (int i = a; i < a + 8; i++) {
		for (int j = b; j < b + 8; j++) {
			if (i % 2 == 1 && j % 2 == 0 && arr[i][j] != 1) { sum1++; }
			else if (i % 2 == 1 && j % 2 == 1 && arr[i][j] != 2) { sum1++; }
			else if (i % 2 == 0 && j % 2 == 0 && arr[i][j] != 2) { sum1++; }
			else if (i % 2 == 0 && j % 2 == 1 && arr[i][j] != 1) { sum1++; }
		}
	}
	for (int i = a; i < a + 8; i++) {
		for (int j = b; j < b + 8; j++) {
			if (i % 2 == 1 && j % 2 == 0 && arr[i][j] == 1) { sum2++; }
			else if (i % 2 == 1 && j % 2 == 1 && arr[i][j] == 2) { sum2++; }
			else if (i % 2 == 0 && j % 2 == 0 && arr[i][j] == 2) { sum2++; }
			else if (i % 2 == 0 && j % 2 == 1 && arr[i][j] == 1) { sum2++; }
		}
	}
	int arbi = (sum1 < sum2) ? sum1 : sum2;
	return arbi;
}

int main()
{
	int N, M;
	cin >> N >> M;
	int** arr = new int*[N];
	for (int i = 0; i < N; i++) {
		arr[i] = new int[M];
		for (int j = 0; j < M; j++) {
			char c;	cin >> c;
			if (c == 'W') arr[i][j] = 1;
			else { arr[i][j] = 2; }
		}
	}
	int min = 64;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			int arbi = confirm(arr,i,j);
			if (arbi < min) min = arbi;
		}
	}
	cout << min << endl;
	return 0;
}