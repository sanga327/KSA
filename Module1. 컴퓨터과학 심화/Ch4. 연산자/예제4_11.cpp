
// 예제 4-11. 콤마 연산자

#include <stdio.h>
int main(void)
{
	int a = 10, b =20;
	int res;

	res = (++a, ++b);  // res에 저장되는 값은 증가된 b의 값

	printf("a:%d, b:%d\n", a, b);
	printf("res:%d\n", res);

	return 0;
} 