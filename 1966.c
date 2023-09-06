#include<stdio.h>
#include<stdlib.h>
// int형 큐 IntQueue(헤더)
#ifndef ___IntQueue
#define ___IntQueue

/*--- 큐를 구현하는 구조체 ---*/
typedef struct {
    int max;    // 큐의 최대 용량
    int num;    // 현재의 데이터 수
    int front;  // 맨 앞 요소 커서
    int rear;   // 맨 뒤 요소 커서
    int* que;   // 큐의 맨 앞 요소에 대한 포인터
} IntQueue;

/*--- 큐 초기화 ---*/
int Initialize(IntQueue* q, int max);

/*--- 큐에 데이터를 인큐 ---*/
int Enque(IntQueue* q, int x);

/*--- 큐에서 데이터를 디큐 ---*/
int Deque(IntQueue* q, int* x);

/*--- 큐에서 데이터를 피크 ---*/
int Peek(const IntQueue* q, int* x);

/*--- 모든 데이터 삭제 ---*/
void Clear(IntQueue* q);

/*--- 큐의 최대 용량 ---*/
int Capacity(const IntQueue* q);

/*--- 큐에 저장된 데이터 수 ---*/
int Size(const IntQueue* q);

/*--- 큐가 비어 있는가? ---*/
int IsEmpty(const IntQueue* q);

/*--- 큐가 가득 찼는가? ---*/
int IsFull(const IntQueue* q);

/*--- 큐에서 검색 ---*/
int Search(const IntQueue* q, int x);

/*--- 큐에서 검색(논리적 인덱스를 반환) ---*/
int Search2(const IntQueue* q, int x);

/*--- 모든 데이터 출력 ---*/
void Print(const IntQueue* q);

/*--- 큐 종료 ---*/
void Terminate(IntQueue* q);

#endif



/*--- 큐 초기화 ---*/
int Initialize(IntQueue* q, int max)
{
    q->num = q->front = q->rear = 0;
    if ((q->que = calloc(max, sizeof(int))) == NULL) {
        q->max = 0;                             // 배열 생성에 실패
        return -1;
    }
    q->max = max;
    return 0;
}

/*--- 큐에 데이터를 인큐 ---*/
int Enque(IntQueue* q, int x)
{
    if (q->num >= q->max)
        return -1;                              // 큐가 가득 참
    else {
        q->num++;
        q->que[q->rear++] = x;
        if (q->rear == q->max)
            q->rear = 0;
        return 0;
    }
}

/*--- 큐에서 데이터를 디큐 ---*/
int Deque(IntQueue* q, int* x)
{
    if (q->num <= 0)                            // 큐가 비어 있음
        return -1;
    else {
        q->num--;
        *x = q->que[q->front++];
        if (q->front == q->max)
            q->front = 0;
        return 0;
    }
}

/*--- 큐에서 데이터를 피크 ---*/
int Peek(IntQueue* q, int* x)
{
    if (q->num <= 0)                            // 큐가 비어 있음
        return -1;
    *x = q->que[q->front];
    return 0;
}

/*--- 모든 데이터 삭제 ---*/
void Clear(IntQueue* q)
{
    q->num = q->front = q->rear = 0;
}

/*--- 큐의 최대 용량 ---*/
int Capacity(const IntQueue* q)
{
    return q->max;
}

/*--- 큐에 쌓여 있는 데이터 수 ---*/
int Size(const IntQueue* q)
{
    return q->num;
}

/*--- 큐가 비어 있는가? ---*/
int IsEmpty(const IntQueue* q)
{
    return q->num <= 0;
}

/*--- 큐가 가득 찼는가? ---*/
int IsFull(const IntQueue* q)
{
    return q->num >= q->max;
}

/*--- 큐에서 검색 ---*/
int Search(const IntQueue* q, int x)
{
    for (int i = 0; i < q->num; i++) {
        int idx;
        if (q->que[idx = (i + q->front) % q->max] == x)
            return idx;     // 검색 성공
    }
    return -1;              // 검색 실패
}

/*--- 큐에서 검색(논리적 인덱스를 반환) ---*/
int Search2(const IntQueue* q, int x)
{
    for (int i = 0; i < q->num; i++) {
        if (q->que[(i + q->front) % q->max] == x)
            return i;       // 검색 성공
    }
    return -1;              // 검색 실패
}

/*--- 모든 데이터 출력 ---*/
void Print(const IntQueue* q)
{
    for (int i = 0; i < q->num; i++)
        printf("%d ", q->que[(i + q->front) % q->max]);
    putchar('\n');
}

/*--- 큐 종료 ---*/
void Terminate(IntQueue* q)
{
    if (q->que != NULL)
        free(q->que);                           // 배열을 해제
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
            if (b < a) { b = a; }//b는 가장 큰 수
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