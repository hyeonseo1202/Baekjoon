#include<iostream>
#include<cstdint>
using namespace std;

int main()
{
	unsigned long long S;
	cin >> S;
	unsigned long long num = 0;
	unsigned long long sum = 0;
	if (S == 1) cout << "1";
	else {
		while (1)
		{
			if (S < sum) break;
			num++;
			sum += num;
		}
		cout << num - 1;
	}
}