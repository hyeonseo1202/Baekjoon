//20044
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;


int main()
{
	int n;
	cin >> n; //팀의 수
	int S[10000]; //개인
	int W[5000];//팀의 코딩역량

	
	for (int i = 0; i < n * 2; i++) {
		cin >> S[i];		
	}
	int temp=0;
	for (int i = 0; i < n * 2; i++) {
		for (int j = 0; j < n * 2-1; j++) {
			if (S[j] > S[j + 1]) {
				temp = S[j];
				S[j] = S[j + 1];
				S[j + 1] = temp;
			}
		}
	}
	/*for (int i = 0; i < n * 2; i++) {
		cout << S[i]<<" ";
	}
	cout << endl;*/
	for (int i = 0, j = n * 2 - 1; i < n; i++, j--) {
		W[i] = S[i] + S[j];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1; j++) {
			if (W[j] > W[j + 1]) {
				temp = W[j];
				W[j] = W[j + 1];
				W[j + 1] = temp;
			}
		}
	}
	/*for (int i = 0; i < n; i++) {
		cout << W[i];
	}
	cout << endl;*/
	cout << W[0];
	return 0;
}
