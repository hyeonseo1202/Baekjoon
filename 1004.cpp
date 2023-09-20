#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int T,n;
	int x1, x2, y1, y2;
	int x, y, r;
	int in, out;
	queue<int>q;
	cin >> T;
	for (int i = 0; i < T;i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> n;
		
		in = 0, out = 0;
		for (int j = 0; j < n;j++) {
			cin >> x >> y >> r;
			if ((x - x1) * (x - x1) + (y - y1) * (y - y1) > r * r) {
				if ((x - x2) * (x - x2) + (y - y2) * (y - y2) < r * r) {
					in++;
				}
			}
			if ((x - x1) * (x - x1) + (y - y1) * (y - y1) < r * r) {
				if ((x - x2) * (x - x2) + (y - y2) * (y - y2) > r * r) {
					out++;
				}
			}
		}
		q.push(in + out);
	}
	while (q.empty() == false) {
		cout << q.front() << endl;
		q.pop();
	}
}