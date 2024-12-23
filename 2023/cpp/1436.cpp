#include<iostream>
using namespace std;

int TF(int i) {
	int num = 0;
	int flag = 0;
	while (i > 0) {
		if (i % 10 == 6) {
			num = 0; flag = 1;
			int j = i;
			while (j > 0 && flag) {
				if (num == 3)break;
				if (j % 10 != 6) flag = 0;
				else { num++; j /= 10; }
			}
			if (num == 3)break;
		}
		i /= 10;
	}
	return (num >= 3);
}

int main()
{
	int N; cin >> N;
	if (N == 1) {
		cout << 666 << endl;
	}
	else {
		int num = 1;
		for (int i = 1666;; i++) {
			if (TF(i))num++;
			if (num == N) { cout << i << endl; return 0; }
		}
	}
}