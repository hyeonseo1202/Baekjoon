#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Cmax 10000



int main() {
	int n;
	
	while(1){
		
		scanf("\n%d", &n);
		char c[Cmax];
		if (n == 0) {
			break;
		}
		scanf("%s", c);
		

		//�빮�ڷ� ����
		_strupr(c);

		//�ߤӾ�� ����	
		char* str = (char*)malloc(sizeof(c));
		int i, k = 0;
		for (i = 0; i < strlen(c); i++) {
			if (c[i] != ' ') str[k++] = c[i];
		}
		str[k] = '\0';

		// ��ȣȭ
		char *a = (char*)malloc(sizeof(str));
		int first = 0;
		for (int j = 0, k = 0; j < strlen(str); j++, k += n) {
			if (k >= strlen(str)) {
				first++;
				k = first;
			}
			a[k] = str[j];
		}
		a[strlen(str)] = '\0';

		//���
		printf("%s", a);
		free(a);
		free(str);
		

	}
	return 0;
}