#include<stdio.h>
#include<stdlib.h>
#define max 300000

typedef struct {
	int max;
	int ptr;
	int* stk;
}IntStack;
int num = 0;

int main() {
	int N, P;
	scanf("%d %d", N, P);//���� ��, ������ ��
	int *n = calloc(N, sizeof(int));
	int* p = calloc(N, sizeof(int));
	
	for (int i = 0; i < N; i++) {
		scanf("%d %d", n[i], p[i]);
	}
    IntStack s1; Initialize(&s1, max);
    IntStack s2; Initialize(&s2, max);
    IntStack s3; Initialize(&s3, max);
    IntStack s4; Initialize(&s4, max);
    IntStack s5; Initialize(&s5, max);
    IntStack s6; Initialize(&s6, max);

    if(n[0])



}
/*--- ���� �ʱ�ȭ ---*/
int Initialize(IntStack* s, int max)
{
    s->ptr = 0;
    if ((s->stk = calloc(max, sizeof(int))) == NULL) {
        s->max = 0;                             // �迭�� ������ ����
        return -1;
    }
    s->max = max;
    return 0;
}

/*--- ���ÿ� ������ Ǫ�� ---*/
int Push(IntStack* s, int x)
{
    if (s->ptr >= s->max)                       // ������ ���� ��
        return -1;
    s->stk[s->ptr++] = x;
    return 0;
}

/*--- ���ÿ��� �����͸� �� ---*/
int Pop(IntStack* s, int* x)
{
    if (s->ptr <= 0)                            // ������ ��� ����
        return -1;
    *x = s->stk[--s->ptr];
    return 0;
}

/*--- ���ÿ��� �����͸� ��ũ ---*/
int Peek(const IntStack* s, int* x)
{
    if (s->ptr <= 0)                            // ������ ��� ����
        return -1;
    *x = s->stk[s->ptr - 1];
    return 0;
}

/*--- ������ ��� ��� ����(Ŭ����) ---*/
void Clear(IntStack* s)
{
    s->ptr = 0;
}

/*--- ������ �ִ� �뷮 ---*/
int Capacity(const IntStack* s)
{
    return s->max;
}

/*--- ���ÿ� �׿� �ִ� ������ �� ---*/
int Size(const IntStack* s)
{
    return s->ptr;
}

/*--- ������ ��� �ִ°�? ---*/
int IsEmpty(const IntStack* s)
{
    return s->ptr <= 0;
}

/*--- ������ ���� á�°�? ---*/
int IsFull(const IntStack* s)
{
    return s->ptr >= s->max;
}

/*--- ���ÿ��� �˻� ---*/
int Search(const IntStack* s, int x)
{
    for (int i = s->ptr - 1; i >= 0; i--)   // �����(top) �� �ٴ�(bottom)���� ���� �˻�
        if (s->stk[i] == x)
            return i;       // �˻� ����
    return -1;              // �˻� ����
}

/*--- ��� ������ ��� ---*/
void Print(const IntStack* s)
{
    for (int i = 0; i < s->ptr; i++)        // �ٴ�(bottom) �� �����(top)�� ��ĵ
        printf("%d ", s->stk[i]);
    putchar('\n');
}

/*--- ���� ���� ---*/
void Terminate(IntStack* s)
{
    if (s->stk != NULL)
        free(s->stk);       // �迭�� ����
    s->max = s->ptr = 0;
}
