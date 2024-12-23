#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	double x[3] = { 0, };
	double y[3] = { 0, };

	double error = -1;
	for (int i = 0; i < 3; i++) {
		scanf("%lf", &x[i]);
		scanf("%lf", &y[i]);
	}
	/*for (int i = 0; i < 3; i++) {
		printf("%lf", x[i]);
		printf("%lf", y[i]);
	}
	printf("\n");*/

	if (x[0] == x[1] && x[1] == x[2]) {
		printf("%.1f", error);
		return 0;
	}
	else if (y[0] == y[1] && y[1] == y[2]) {
		printf("%.1f", error);
		return 0;
	}
	else if(x[0] != x[1] && x[1] != x[2])
	{
		
		double rate[2] = { 0, };//기울기
		rate[0] = (y[1] - y[0]) / (x[1] - x[0]);
		rate[1] = (y[2] - y[1]) / (x[2] - x[1]);
		
		//printf("%lf %lf\n", rate[0], rate[1]);

	    if (rate[0] == rate[1]) {
	    printf("%.1lf", error);
	    return 0;
	    }
	}
	double length = 0;//두 점 사이 거리
	double len[3] = { 0, };
	len[0] = sqrt(((x[0] - x[1]) * (x[0] - x[1])) + ((y[0] - y[1]) * (y[0] - y[1])));
	len[1] = sqrt(((x[1] - x[2]) * (x[1] - x[2])) + ((y[1] - y[2]) * (y[1] - y[2])));
	len[2] = sqrt(((x[0] - x[2]) * (x[0] - x[2])) + ((y[0] - y[2]) * (y[0] - y[2])));
	//printf("%lf %lf %lf\n", len[0], len[1], len[2]);
	

	//버블 정렬
	for (int i = 0; i < 2; i++) {// 오름차순 정렬
		for (int j = 0; j < 2; j++) {
			if (len[j] > len[j + 1]) {
				double tmp = len[j];
				len[j] = len[j + 1];
				len[j + 1] = tmp;
			}
		}
	}
	//printf("%lf %lf %lf\n", len[0], len[1], len[2]);
	double min = 0, max = 0;
	min = (len[0] + len[1]) * 2;
	max = (len[2] + len[1]) * 2;

	double result = max - min;
	printf("%.15lf", result);

	return 0;

}