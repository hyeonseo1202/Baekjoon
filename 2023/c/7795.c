#include<stdio.h>
#include<stdlib.h>

int compare(const void* num1, const void* num2)
{
	if (*(int*)num1 < *(int*)num2)
		return -1;

	if (*(int*)num1 > *(int*)num2)
		return 1;
	else
		return 0;
}
int main() {
	int T,N,M;
	scanf("%d", &T);
	int* t = (int*)calloc(T, sizeof(int));
	for (int k = 0; k < T; k++) {
		scanf("%d %d", &N, &M);
		int* a = (int*)calloc(N, sizeof(int));
		for (int i = 0; i < N; i++) {
			scanf("%d", &a[i]);
		}
		int* b = (int*)calloc(M, sizeof(int));
		for (int i = 0; i < M; i++) {
			scanf("%d", &b[i]);
		}
		qsort(a, N, sizeof(int), compare);
		qsort(b, M, sizeof(int), compare);

		int num = 0,n = 0;
		
		for (int i = 0; i < M; i++)
		{
			if (a[n] > b[i]) {
				num += (N - n);
			}
			else {
				n++;
				if (n == N) break;
				i--;
			}
		}
		t[k] = num;
		free(a);
		free(b);
	}
	for (int k = 0; k < T; k++) {
		printf("%d\n", t[k]);
	}
	
	free(t);
	
	return 0;
}