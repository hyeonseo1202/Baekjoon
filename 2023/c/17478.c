#include<stdio.h>
int a=0;


void recur(int n ) {
	
	if (n > 0) {
		for (int i = 0; i < a * 4; i++) {
			printf("_");
		}
		printf("\"����Լ��� ������?\"\n");
		for (int i = 0; i < a * 4; i++) {
			printf("_");
		}
		printf("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n");
		for (int i = 0; i < a * 4; i++) {
			printf("_");
		}
		printf("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n");
		for (int i = 0; i < a * 4; i++) {
			printf("_");
		}
		printf("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n");

		a++;

		recur(n - 1);
		a--;
		for (int i = 0; i < a * 4; i++) {
			printf("_");
		}
		printf("��� �亯�Ͽ���.\n");
		
		
	}
	else if (n == 0) {
		for (int i = 0; i < a * 4; i++) {
			printf("_");
		}
		printf("\"����Լ��� ������?\"\n");
		for (int i = 0; i < (a) * 4; i++) {
			printf("_");
		}
		printf("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n");
		for (int i = 0; i < a * 4; i++) {
			printf("_");
		}
		printf("��� �亯�Ͽ���.\n");
		return;
	}
	
}
int main() {
	int n;
	scanf("%d", &n);
	printf("��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n");
	recur(n);

}