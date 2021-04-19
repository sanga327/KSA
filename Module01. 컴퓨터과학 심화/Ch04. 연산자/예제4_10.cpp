
// 예제 4-10. 복합대입 연산자

#include <stdio.h>
int main(void)
{
	int a = 10, b =20;
	int res = 2;

	a += 20;
	res *= b+10;   // b+10 값에 res 곱하고 다시 res에 저장

	printf("a = %d, b = %d\n", a,b);
	printf("res = %d\n", res);

	return 0;
}