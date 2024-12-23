#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	int* arr;
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int* out;
	out = (int*)malloc(sizeof(int) * n);
	int *visit = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		visit[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		int j = -1;
		while (++j < n)
		{
			if (arr[j] < arr[i])
				count++;
		}
		while (visit[count] == 1)
			count++;
		out[i] = count;
		visit[count] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", out[i]);
	}

}