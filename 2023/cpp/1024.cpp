#include<iostream>
using namespace std;

int main()
{
	int N, L;
	cin >> N >> L;

	while (L <= 100) {
		int numerator = N - (L - 1) * L / 2;
		if (numerator % L == 0 && numerator / L >= 0) {
			int start = numerator / L;
			for (int i = 0; i < L; i++) {
				cout << start + i << " ";
			}
			return 0;
		}
		L++;
	}
	cout << -1;
	return 0;
}
