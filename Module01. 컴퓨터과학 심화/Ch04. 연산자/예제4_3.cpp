

// 예제 4-3. 증감 연산자 - 피연산자의 값을 1 증가시키거나 감소시킨다.

#include <stdio.h>
int main(void)
{
	int a = 10, b = 10;

	++a;   // 변수의 값을 1만큼 증가
	--b;   // 변수의 값을 1만큼 감소

	printf("a: %d\n", a);
	printf("b: %d\n", b);

		return 0;
}
