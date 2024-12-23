#include<stdio.h>
#include<stdlib.h>

int main() 
{
	int C, N,tmp=0;
	scanf("%d", &C);
	float* b = (float*)calloc(C,sizeof(float));
	for (int i = 0; i < C; i++) {
		scanf("%d", &N);
		int *a = (int *)calloc(N, sizeof(int));		
		
		float sum = 0, avg = 0;
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[j]);
			sum += a[j];
		}
		avg = sum /(float) N;
		int num = 0;
		for (int j = 0; j < N; j++) {
			if (a[j] > avg) {
				num += 1;
			}
		}
		float percent = ((float)num / N)*100;	
		b[tmp] = percent;
		tmp++;
		free(a);
	}
	for (int i = 0; i < C; i++) {
		printf("%.3f%%\n", b[i]);
	}
	free(b);
	return 0;
}