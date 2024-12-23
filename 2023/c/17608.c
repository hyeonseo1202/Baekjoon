#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int ptr;//���� ����
    int *stk;//�迭
    int max;//�ִ� �뷮
}IntStack;

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
int  Pop(IntStack* s)
{
    if (s->ptr <= 0)                            // ������ ��� ����
        return -1;
    s->stk[--s->ptr];
    
}

/*--- ���ÿ��� �����͸� ��ũ ---*/
int Peek(const IntStack* s)
{
    if (s->ptr <= 0)                            // ������ ��� ����
        return -1;
    return s->stk[s->ptr - 1];
    
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
int main() {
    int n;
    scanf_s("%d",&n);

    IntStack a;
    if (Initialize(&a, n) == -1) {
        puts("���� ������ �����߽��ϴ�.");
        return 1;
    }
    int* b = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &b[i]);
        Push(&a, b[i]);
    }
    int tmp = Peek(&a);
    int num = 1;
    Pop(&a);
    for (int i = 0, j = n - 2; i < n - 1; i++, j--) {
        if (tmp >= Peek(&a)) {
            Pop(&a);
        }
        else {
            tmp = Peek(&a);
            Pop(&a);
            num++;
        }
    }
    printf("%d", num);
    free(b);

}