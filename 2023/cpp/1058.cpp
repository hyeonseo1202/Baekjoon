#include<iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int arr[50][50];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char c;
			cin >> c;
			if (c == 'Y') { arr[i][j] = 1; }
			else { arr[i][j] = 0; }
		}
	}//입력받기 - 친구이면 1 ,아니면 0
	int* result = new int[N];
	for(int i = 0;i<N;i++){
		result[i] = 0;
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			//i번째 친구 수 세기
			if (i == j) continue;
			else if (arr[i][j]) result[i]++;
			else {
				for (int k = 0; k < N; k++) {
					if (arr[i][k] && arr[j][k])
					{
						result[i]++;
						break;
					}
				}
			}
		}
	}
	int highest = result[0];
	for (int i = 1; i < N; i++) {
		if (result[i] > highest) highest = result[i];
	}
	cout << highest;
	return 0;
}