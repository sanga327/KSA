
// 예제 4-7. 연산의 결과값을 처리하는 방법

#include <stdio.h>
int main(void)
{
	int a = 10, b = 20, res;

	a+b;
	printf("%d + %d = %d\n", a,b,a+b);
	
	res = a+b;
	printf("%d + %d = %d\n", a,b,res);

	return 0;
}