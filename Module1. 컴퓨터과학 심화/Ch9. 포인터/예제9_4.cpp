
// 예제 9-4. const를 사용한 포인터

#include <stdio.h>
int main(void) {
	int a= 10, b = 20;
	const int *pa = &a;

	printf("변수 a의 값: %d\n", *pa);
	pa = &b;

	printf("변수 b의 값: %d\n", *pa);
	pa = &a;
	a = 20;
	printf("변수 a의 값: %d\n", *pa);

	return 0;
}
