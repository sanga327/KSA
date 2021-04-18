// 예제 8-2. 함수화

#include <stdio.h>

double avg(int n);

int main(void) {
	double t = avg(4);
	printf("평균: %.1lf", t);
}

double avg(int n) {

	int score[100];
	int i;
	int total = 0;
	double avg_v;

	for (i = 0; i < n; i++) {
		scanf_s("%d", &score[i]);
		total += score[i];
	}

	avg_v = double(total) / double(n);

	return avg_v;
}
