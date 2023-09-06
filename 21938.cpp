//21938
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int N, M;
int K[1000][3000];
int A[1000][1000];

class Pos {
	int row, col;
public:
	Pos(int r = 0, int c = 0) { row = r; col = c; }
	Pos Up() { return Pos(row - 1, col); }
	Pos Down() { return Pos(row + 1, col); }
	Pos Left() { return Pos(row, col - 1); }
	Pos Right() { return Pos(row, col + 1); }
	bool Invaild() {
		return (row < 0 || row >= N || col < 0 || col >= M || K[row][col] != 255);
	}
	void Visit() {
		K[row][col] = 0;
	}
};
int DepthFirstSearch(Pos p) {
	if (p.Invaild()) { return 0; }
	p.Visit();
	DepthFirstSearch(p.Up());
	DepthFirstSearch(p.Down());
	DepthFirstSearch(p.Left());	
	DepthFirstSearch(p.Right());
	return 1;
}

int main()
{

	cin >> N >> M;

	int T;
	for (int i = 0; i < N; i++)	{
		for (int j = 0; j < M*3; j++) {
			cin >> K[i][j];
		}
	}
	
	cin >> T;
	M *= 3;
	//T를 이용해 정보 보정, 새로운 배열로 만듦
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j+=3) {	
			int mid = (K[i][j] + K[i][j + 1] + K[i][j + 2]) / 3;
			if (mid >= T) {
				K[i][j] = 255;
				K[i][j+1] = 255;
				K[i][j+2] = 255;

			}
			else {
				K[i][j] = 0;
				K[i][j + 1] = 0;
				K[i][j + 2] = 0;
			}
		}
	}


	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			result += DepthFirstSearch(Pos(i, j));
		}
	}
	cout << result;
}