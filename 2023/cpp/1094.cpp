#include<iostream>
#include<stack>
using namespace std;

int main()
{
	int X;
	cin >> X;

	int sum = 64;
	stack<int>s;
	s.push(64);
	if (X == 64) cout << 1;
	else {
		while (1)
		{
			int a = s.top() / 2;
			s.pop();
			s.push(a);
			if (X < sum - s.top()) { sum -= s.top(); }
			else if (X == sum - s.top()) {
				cout << s.size() << endl;
				return 0;
			}
			else {
				s.push(a);
			}
		}
	}
}