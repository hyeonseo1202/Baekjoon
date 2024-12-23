#include<iostream>
using namespace std;

int main()
{
	int w, h, x, y;
	cin >> x >> y >> w >> h;

	int minx = 0,miny = 0, result = 0;
	if (x >= w - x) minx = w - x;
	else { minx = x; }
	if (y >= h - y) miny = h - y;
	else { miny = y; }
	if (minx >= miny) { result = miny; }
	else { result = minx; }
	cout << result;
	return 0;
}