#include<stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int j = (n * 2) - 1;
	int tmp = 1 + (n - 1) * 4;
	int a = n;
	if (n == 1) {
		printf("*");
	}
	else {
		for (int i = 1; i <= j; i++) {

			if (i % 2 == 0) {//Â¦¼ö¹øÂ°ÁÙ
				for (int k = 0; k < i / 2; k++) {
					printf("* ");
				}
				for (int k = 0; k < 1 + (a - 1) * 4; k++) {
					printf(" ");
				}
				for (int k = 0; k < i / 2; k++) {
					printf(" *");
				}
				printf("\n");
				

			}
			else {//È¦¼ö¹øÂ°ÁÙ
				for (int k = 0; k < i / 2; k++) {
					printf("* ");
				}
				for (int k = 0; k < 1 + (a - 1) * 4; k++) {
					printf("*");
				}
				for (int k = 0; k < i / 2; k++) {
					printf(" *");
				}
				printf("\n");
				
				a--;
			}

		}
		a++;
		for (int i = j - 1; i > 0; i--) {

			if (i % 2 == 0) {//Â¦¼ö¹øÂ°ÁÙ

				for (int k = 0; k < i / 2; k++) {
					printf("* ");
				}
				for (int k = 0; k < 1 + (a - 1) * 4; k++) {
					printf(" ");
				}
				for (int k = 0; k < i / 2; k++) {
					printf(" *");
				}
				printf("\n");
				
				a++;

			}
			else {//È¦¼ö¹øÂ°ÁÙ
				for (int k = 0; k < i / 2; k++) {
					printf("* ");
				}
				for (int k = 0; k < 1 + (a - 1) * 4; k++) {
					printf("*");
				}
				for (int k = 0; k < i / 2; k++) {
					printf(" *");
				}
				if (i == 1) { break; }
				printf("\n");
				
			}

	}
	
	}
	return 0;
}