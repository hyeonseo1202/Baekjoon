#include<stdio.h>
#define MAX 100
int main() {
	long int n;//���� ����� ��
	char name[MAX][MAX], inout[MAX][MAX];
	char fin[MAX][MAX];
	do {
		scanf_s("%d", &n);
	} while (n >= 2 || n <= 1000000);

	int k = 0;
	for (int i = 0; i < n; i++) {
		scanf_s("%s %s", &name[i], &inout[i]);
		if (inout[i] == "enter") {//���� ���
			fin[k][] = name[i];
			k++;
		}
		else {//���� ���
			for (int j = 0; j < i; j++) {//��ġ ã��
				if (name[i] == fin[j]) { //j�� �� ��ġ
					for (int l = j; l < k; l++) {//���Ž�Ű��
						fin[l] = fin[l + 1];
					}
					k--;//���� �ο��� ��ü ���ڿ� �� ���̱�
				}
			}
		}
	}
	for (int i = 0; i <= k; i++) {
		printf("%s\n", fin[i]);
	}
	return 0;	
}