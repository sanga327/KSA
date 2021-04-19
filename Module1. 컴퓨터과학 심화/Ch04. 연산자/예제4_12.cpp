
// 예제 4-12. 조건 연산자

#include <stdio.h>
int main(void)
{
	int a = 10, b= 20, res;

	res = (a>b) ? a:b;    // a와 b 중 큰 값이 res에 저장
	printf("큰 값: %d\n", res);

	return 0;
}

