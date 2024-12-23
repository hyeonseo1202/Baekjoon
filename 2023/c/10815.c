#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int bin_search(const int a[], int n, int key)
{
    int pl = 0;
    int pr = n - 1;

    do
    {
        int pc = (pl + pr) / 2;
        if (a[pc] == key)
            return 1;
        else if (a[pc] < key)
            pl = pc + 1;
        else if (a[pc] > key)
            pr = pc - 1;
    } while (pl <= pr);

    return 0;
}

int main()
{
    int N, M, x;
    scanf(" %d", &N);
    int* h = (int *)calloc(N, sizeof(int));
    for (int i = 0; i < N; i++)
        scanf(" %d ", &h[i]);
    scanf(" %d", &M);
    int* c = (int *)calloc(M, sizeof(int));
    for (int i = 0; i < M; i++)
        scanf(" %d ", &c[i]);

    for (int i = 0; i < M; i++)
    {
        x = bin_search(h, N, c[i]);

        if (x == 1)
            printf("1 ");
        else
            printf("0 ");
    }

    

    free(h);
    free(c);

    return 0;
}