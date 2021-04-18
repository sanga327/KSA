
// 예제 4-5. 관계 연산자
#include <stdio.h>
int main(void)
{
	int a = 10, b= 20, c = 10;
	int res;  

	res = (a>b);
	printf("a>b: %d\n", res);

	res = (a>=b);
	printf("a>=b: %d\n", res);
	
	res = (a<b);
	printf("a<b: %d\n", res);

	res = (a<=b);

	printf("a<=b: %d\n", res);
	res = (a<=c);
	printf("a<=c: %d\n", res);

	res = (a==b);
	printf("a==b: %d\n", res);

	res = (a!=c);
	printf("a!=c: %d\n", res);
	
	return 0;
}

