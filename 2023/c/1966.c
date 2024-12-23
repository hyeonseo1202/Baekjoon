#include<stdio.h>
#include<stdlib.h>
// int�� ť IntQueue(���)
#ifndef ___IntQueue
#define ___IntQueue

/*--- ť�� �����ϴ� ����ü ---*/
typedef struct {
    int max;    // ť�� �ִ� �뷮
    int num;    // ������ ������ ��
    int front;  // �� �� ��� Ŀ��
    int rear;   // �� �� ��� Ŀ��
    int* que;   // ť�� �� �� ��ҿ� ���� ������
} IntQueue;

/*--- ť �ʱ�ȭ ---*/
int Initialize(IntQueue* q, int max);

/*--- ť�� �����͸� ��ť ---*/
int Enque(IntQueue* q, int x);

/*--- ť���� �����͸� ��ť ---*/
int Deque(IntQueue* q, int* x);

/*--- ť���� �����͸� ��ũ ---*/
int Peek(const IntQueue* q, int* x);

/*--- ��� ������ ���� ---*/
void Clear(IntQueue* q);

/*--- ť�� �ִ� �뷮 ---*/
int Capacity(const IntQueue* q);

/*--- ť�� ����� ������ �� ---*/
int Size(const IntQueue* q);

/*--- ť�� ��� �ִ°�? ---*/
int IsEmpty(const IntQueue* q);

/*--- ť�� ���� á�°�? ---*/
int IsFull(const IntQueue* q);

/*--- ť���� �˻� ---*/
int Search(const IntQueue* q, int x);

/*--- ť���� �˻�(���� �ε����� ��ȯ) ---*/
int Search2(const IntQueue* q, int x);

/*--- ��� ������ ��� ---*/
void Print(const IntQueue* q);

/*--- ť ���� ---*/
void Terminate(IntQueue* q);

#endif



/*--- ť �ʱ�ȭ ---*/
int Initialize(IntQueue* q, int max)
{
    q->num = q->front = q->rear = 0;
    if ((q->que = calloc(max, sizeof(int))) == NULL) {
        q->max = 0;                             // �迭 ������ ����
        return -1;
    }
    q->max = max;
    return 0;
}

/*--- ť�� �����͸� ��ť ---*/
int Enque(IntQueue* q, int x)
{
    if (q->num >= q->max)
        return -1;                              // ť�� ���� ��
    else {
        q->num++;
        q->que[q->rear++] = x;
        if (q->rear == q->max)
            q->rear = 0;
        return 0;
    }
}

/*--- ť���� �����͸� ��ť ---*/
int Deque(IntQueue* q, int* x)
{
    if (q->num <= 0)                            // ť�� ��� ����
        return -1;
    else {
        q->num--;
        *x = q->que[q->front++];
        if (q->front == q->max)
            q->front = 0;
        return 0;
    }
}

/*--- ť���� �����͸� ��ũ ---*/
int Peek(IntQueue* q, int* x)
{
    if (q->num <= 0)                            // ť�� ��� ����
        return -1;
    *x = q->que[q->front];
    return 0;
}

/*--- ��� ������ ���� ---*/
void Clear(IntQueue* q)
{
    q->num = q->front = q->rear = 0;
}

/*--- ť�� �ִ� �뷮 ---*/
int Capacity(const IntQueue* q)
{
    return q->max;
}

/*--- ť�� �׿� �ִ� ������ �� ---*/
int Size(const IntQueue* q)
{
    return q->num;
}

/*--- ť�� ��� �ִ°�? ---*/
int IsEmpty(const IntQueue* q)
{
    return q->num <= 0;
}

/*--- ť�� ���� á�°�? ---*/
int IsFull(const IntQueue* q)
{
    return q->num >= q->max;
}

/*--- ť���� �˻� ---*/
int Search(const IntQueue* q, int x)
{
    for (int i = 0; i < q->num; i++) {
        int idx;
        if (q->que[idx = (i + q->front) % q->max] == x)
            return idx;     // �˻� ����
    }
    return -1;              // �˻� ����
}

/*--- ť���� �˻�(���� �ε����� ��ȯ) ---*/
int Search2(const IntQueue* q, int x)
{
    for (int i = 0; i < q->num; i++) {
        if (q->que[(i + q->front) % q->max] == x)
            return i;       // �˻� ����
    }
    return -1;              // �˻� ����
}

/*--- ��� ������ ��� ---*/
void Print(const IntQueue* q)
{
    for (int i = 0; i < q->num; i++)
        printf("%d ", q->que[(i + q->front) % q->max]);
    putchar('\n');
}

/*--- ť ���� ---*/
void Terminate(IntQueue* q)
{
    if (q->que != NULL)
        free(q->que);                           // �迭�� ����
    q->max = q->num = q->front = q->rear = 0;
}

int main() {
    IntQueue que;
    Initialize(&que, 100);
    int n;
    int answer[100];
    scanf("%d ", &n);
    int N, M;    
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &N, &M);
        }
        int b = 0;
        for (int i = 0; i < N; i++) {
            int a;
            scanf("%d ", &a);
            Enque(&que, a);
            if (b < a) { b = a; }//b�� ���� ū ��
        }
        int x;

        while (1) {

            if (b == Peek(&que, &x)) {
                break;
            }
            Peek(&que, &x);
            int tmp = x;
            Deque(&que, &x);

            if (Peek(&que, &x) >= tmp) {
                Enque(&que, tmp);
            }
        }
        answer[k] = Search(&que, M);
    }
    for (int k = 0; k < n; k++) {
        printf("%d\n", answer[k]);
    }
 219121
     191212
     912121
     12121
     21211
     1211
     2111
     111
     11
     1

   
    
}