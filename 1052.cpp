#include<iostream>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	int cnt;
	int income = -1;
	if (K >= N)cout << 0 << endl;
	else {
		N--;
		do {
			cnt = 0; income++; N++;
			int a = N, b = 0;
			while (1)
			{
				if (b == 1) cnt++;
				if (a == 0 || a == 1)
				{
					if (a == 1) cnt++;
					break;
				}
				b = a % 2;
				a = a / 2;
			}
		} while (K < cnt);
		cout << income << endl;
	}
	return 0;
}