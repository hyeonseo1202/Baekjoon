#include<stdio.h>
#include<stdlib.h>

int main()
{
	long long N;
	long long n[6] = { 0, };
	do {
		scanf("%lld", &N);
	} while (N > 1000000 && N < 0);

	for (long long i = 0; i < 6; i++) {
		do {
			scanf("%lld", &n[i]);
		} while (n[i] > 50 && n[i]< 0);
	}
	long long sum=0;
	long long first, second, third;
	if (N == 1) {
		int temp = n[0];
		int D = 0;
		for (int i = 0; i < 6; i++) {
			if (temp <= n[i]) {
				temp = n[i];
				D = i;
			}
		}
		for (int i = 0; i < 6; i++) {
			if (i == D) {}
			else {
				sum += n[i];
			}
		
		}
		printf("%lld", sum);
	}
	else {

		long long thr[8];
		thr[0] = n[0] + n[1] + n[2];
		thr[1] = n[0] + n[2] + n[4];
		thr[2] = n[0] + n[4] + n[3];
		thr[3] = n[0] + n[3] + n[1];
		thr[4] = n[5] + n[1] + n[2];
		thr[5] = n[5] + n[2] + n[4];
		thr[6] = n[5] + n[4] + n[3];
		thr[7] = n[5] + n[3] + n[1];
		third = thr[0];
		for (int i = 0; i < 8; i++) {
			if (third > thr[i]) {
				third = thr[i];
			}
		}

		third = 4 * third;

		long long sec[12];
		sec[0] = n[0] + n[1];
		sec[1] = n[0] + n[2];
		sec[2] = n[0] + n[3];
		sec[3] = n[0] + n[4];
		sec[4] = n[5] + n[1];
		sec[5] = n[5] + n[2];
		sec[6] = n[5] + n[3];
		sec[7] = n[5] + n[4];
		sec[8] = n[1] + n[2];
		sec[9] = n[2] + n[4];
		sec[10] = n[4] + n[3];
		sec[11] = n[3] + n[1];
		second = sec[0];
		for (long long i = 0; i < 12; i++) {
			if (second > sec[i]) {
				second = sec[i];
			}
		}
		second = ((N - 2) * 8 * second) + (4 * second);


		first = n[0];
		for (long long i = 0; i < 6; i++) {
			if (first >= n[i]) {
				first = n[i];
			}
		}
		first = ((N - 2) * (N - 2) * 5 * first) + ((N - 2) * 4 * first);

		sum = first + second + third;
		printf("%lld", sum);
	}
	return 0;
}