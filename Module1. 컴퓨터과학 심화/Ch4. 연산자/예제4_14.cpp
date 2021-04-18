

// 예제 4-14. 

#include <stdio.h>
int main(void)
{
	int a=10, b=5;
	int res;
	
	res = a/b*2;
	printf("res = %d\n", res);   // 4

	res = ++a*3;
	printf("res = %d\n", res);   // 33

	res = a>b && a!=5;  // a>b의 결과와 a!=5의 결과를 &&연산
	printf("res = %d\n", res);   // 1

	res = a%3==0;
	printf("res = %d\n", res);   // 0

}
