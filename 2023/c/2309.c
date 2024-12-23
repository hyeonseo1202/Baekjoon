#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- 버블 정렬 ---*/
void bubble(int a[], int n)
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j > i; j--)
			if (a[j - 1] > a[j])
				swap(int, a[j - 1], a[j]);
	}
}

int main()
{
	int a[9] = { 0, };
	for (int i = 0; i < 9; i++) {
		do {			
			scanf("%d", &a[i]);
		} while (a[i] > 100);
	}
	printf("\n");
	bubble(a, 9);
	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (i == j){}
			else 
			{
				int sum = 0;
				int n = 0;
				int b[7] = { 0, };
				for (int k = 0; k < 9;k++) {
					if (k != i && k != j) {
						sum += a[k];
						b[n] += a[k];
						n++;
					}

				}
				if (sum == 100) {
					for (int l = 0; l < 7; l++) {
						printf("%d\n", b[l]);
					}
					return 0;
					
				}
			}
		}
	}

	
}