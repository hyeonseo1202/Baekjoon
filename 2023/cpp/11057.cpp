//#include<iostream>
//using namespace std;
//int combination(int n, int r) {
//	if (n == r || r == 0)
//		return 1;
//	else
//		return combination(n - 1, r - 1) + combination(n - 1, r);
//}
//int main() {
//	int N;
//	do {
//		cin >> N;
//	} while (N > 1000 || N < 0);
//	unsigned long long int a = N + 9;
//	unsigned long long int result = 1;
//	for (int i = 0; i <N; i++,a--) {
//		result *= a;		
//	}
//	for (int i = 1; i <= N; i++) {
//		result /= i;
//	}
//	cout << result % 10007;
//}