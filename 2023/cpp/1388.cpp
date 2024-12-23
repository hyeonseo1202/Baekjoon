//1388
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int arr1[50][50];
int arr2[50][50];
int N, M;
bool Invaild1(int n, int m) {
	if (n >= N || n < 0 || m >= M || m < 0
	    || arr1[n][m] != 1 ) {
		return true;;
	}
	return false;
}
void Visit1(int n,int m) {
	arr1[n][m] = 0;
}

bool DFS1(int n, int m)
{
	if (Invaild1(n, m)) return false;
	Visit1(n, m);
	DFS1(n, m + 1);
	return true;
}
bool Invaild2(int n, int m) {
	if (n >= N || n < 0 || m >= M || m < 0
		|| arr2[n][m] != 0) {
		return true;
	}
	return false;
}
void Visit2(int n, int m) {
	arr2[n][m] = 1;
}
bool DFS2(int n, int m)
{
	if (Invaild2(n, m)) return false;
	Visit2(n, m);
	DFS2(n+1, m);
	return true;
}
int main()
{
	
	cin >> N;//세로, 열, col
	cin >> M;//가로, 행, row
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char C;
			cin >> C;
			if (C == '-') {
				arr1[i][j] = 1;
				arr2[i][j] = 1;
			}
			else if (C == '|') {
				arr1[i][j] = 0;
				arr2[i][j] = 0;
			}
		}
	}
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			result += DFS1(i, j);
			result += DFS2(i, j);
		}
	}
	cout << result;

}