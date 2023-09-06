#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int ptr;//현재 개수
    int *stk;//배열
    int max;//최대 용량
}IntStack;

int Initialize(IntStack* s, int max)
{
    s->ptr = 0;
    if ((s->stk = calloc(max, sizeof(int))) == NULL) {
        s->max = 0;                             // 배열의 생성에 실패
        return -1;
    }
    s->max = max;
    return 0;
}

/*--- 스택에 데이터 푸시 ---*/
int Push(IntStack* s, int x)
{
    if (s->ptr >= s->max)                       // 스택이 가득 참
        return -1;
    s->stk[s->ptr++] = x;
    return 0;
}

/*--- 스택에서 데이터를 팝 ---*/
int  Pop(IntStack* s)
{
    if (s->ptr <= 0)                            // 스택이 비어 있음
        return -1;
    s->stk[--s->ptr];
    
}

/*--- 스택에서 데이터를 피크 ---*/
int Peek(const IntStack* s)
{
    if (s->ptr <= 0)                            // 스택이 비어 있음
        return -1;
    return s->stk[s->ptr - 1];
    
}

/*--- 스택의 모든 요소 삭제(클리어) ---*/
void Clear(IntStack* s)
{
    s->ptr = 0;
}

/*--- 스택의 최대 용량 ---*/
int Capacity(const IntStack* s)
{
    return s->max;
}

/*--- 스택에 쌓여 있는 데이터 수 ---*/
int Size(const IntStack* s)
{
    return s->ptr;
}

/*--- 스택은 비어 있는가? ---*/
int IsEmpty(const IntStack* s)
{
    return s->ptr <= 0;
}

/*--- 스택은 가득 찼는가? ---*/
int IsFull(const IntStack* s)
{
    return s->ptr >= s->max;
}

/*--- 스택에서 검색 ---*/
int Search(const IntStack* s, int x)
{
    for (int i = s->ptr - 1; i >= 0; i--)   // 꼭대기(top) → 바닥(bottom)으로 선형 검색
        if (s->stk[i] == x)
            return i;       // 검색 성공
    return -1;              // 검색 실패
}

/*--- 모든 데이터 출력 ---*/
void Print(const IntStack* s)
{
    for (int i = 0; i < s->ptr; i++)        // 바닥(bottom) → 꼭대기(top)로 스캔
        printf("%d ", s->stk[i]);
    putchar('\n');
}

/*--- 스택 종료 ---*/
void Terminate(IntStack* s)
{
    if (s->stk != NULL)
        free(s->stk);       // 배열을 삭제
    s->max = s->ptr = 0;
}
int main() {
    int n;
    scanf_s("%d",&n);

    IntStack a;
    if (Initialize(&a, n) == -1) {
        puts("스택 생성에 실패했습니다.");
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