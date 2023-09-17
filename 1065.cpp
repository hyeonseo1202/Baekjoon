#include<iostream>
using namespace std;

int right(int num)
{
	if(num < 100)
	{
		return 1;
	}
	else {
		int last = num % 10;
		num /= 10;
		int now = num % 10;
		int diff = last - now;
		num /= 10; last = now;
		while (num > 0)
		{
			now = num % 10;
			num /= 10;
			if (last - now == diff) continue;
			else {
				return 0;
			}
			last = now;
		}
		return 1;
	}
}

int main()
{
	int N;
	cin >> N;

	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		cnt += right(i);
	}
	cout << cnt;
	return 0;
}