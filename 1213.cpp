#include<iostream>
using namespace std;

int main()
{
	int arr[26];
	string str;
	cin >> str;
	for (int i = 0; i < 26; i++)
	{
		arr[i] = 0;
	}
	int i = -1;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			arr[str[i] - 'A']++;
		}
	}
	int type = 0;
	for (int i = 0; i < 26; i++)
	{
		if (arr[i])
			type++;
	}
	int flag = 0;
	for (int i = 0; i < 26; i++)
	{
		if (type % 2 == 0 && arr[i] % 2 == 1)
		{
			cout << "I'm Sorry Hansoo" << endl;
			return 0;
		}
		else if (flag > 1&& type % 2 == 1 && arr[i] % 2 == 1)
		{
			cout << "I'm Sorry Hansoo" << endl;
			return 0;
		}
		else if (type % 2 == 1 && arr[i] % 2 == 1)
		{
			flag++;
		}
	}
	flag = 0;
	for (int i = 0; i < 26; i++)
	{
		if (arr[i] % 2 == 1)
			flag = i + 65;
		if (arr[i])
		{
			char c = i + 65;
			for (int j = 0; j < arr[i] / 2; j++)
			{
				cout << c;
			}
		}
	}
	if (flag) 
	{
		char c = flag;
		cout << c;
	}
	for (int i = 25; i >= 0; i--)
	{
		if (arr[i])
		{
			char c = i + 65;
			for (int j = 0; j < arr[i] / 2; j++)
			{
				cout << c;
			}
		}
	}
	cout << endl;
	return 0;
}