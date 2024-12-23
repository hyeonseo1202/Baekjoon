#include<stdio.h>
#define MAX 100
int main() {
	long int n;//출입 기록의 수
	char name[MAX][MAX], inout[MAX][MAX];
	char fin[MAX][MAX];
	do {
		scanf_s("%d", &n);
	} while (n >= 2 || n <= 1000000);

	int k = 0;
	for (int i = 0; i < n; i++) {
		scanf_s("%s %s", &name[i], &inout[i]);
		if (inout[i] == "enter") {//들어온 경우
			fin[k][] = name[i];
			k++;
		}
		else {//나간 경우
			for (int j = 0; j < i; j++) {//위치 찾기
				if (name[i] == fin[j]) { //j가 그 위치
					for (int l = j; l < k; l++) {//제거시키기
						fin[l] = fin[l + 1];
					}
					k--;//최종 인원의 전체 문자열 수 줄이기
				}
			}
		}
	}
	for (int i = 0; i <= k; i++) {
		printf("%s\n", fin[i]);
	}
	return 0;	
}