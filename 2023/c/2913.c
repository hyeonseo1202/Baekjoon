//#include<stdio.h>
//
//int cal_day(int d1, int m1, int d2, int m2) {
//	int sumday = 0;
//	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//	if (m1 <= m2) {		
//		for (int i = m2 - 1; i >= m1; i--) {
//			sumday += month[i];
//		}
//		sumday += d2- d1;
//	}
//	else {
//		for (int i = 0; i < m2; i++) {
//			sumday += month[i];
//		}
//		for (int i = m1; i < 12; i++) {
//			sumday += month[i];
//		}
//		sumday -= d1;
//		sumday += d2;
//	}
//	return sumday;
//
//}
//int main()
//{
//	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//	int N, M, D1, D2, M1, M2;
//	scanf("%d", &N);
//	scanf("%d", &M);
//	int*
//	scanf("%d %d %d %d", &D1,&M1,&D2,&M2);
//	int* f = (int*)calloc(M, sizeof(int)); //사건 발생 횟수
//	for (int i = 0; i < M; i++) {
//		scanf("%d", &f[i]);
//	}
//	int *lnterval = (int*)calloc(M, sizeof(int)); // 날짜 차이를 저장하기 위한 배열
//
//	
//}