
// 예제 2-6. 실수 상수 표현법
#include <stdio.h>
int main(void)
{
	printf("%.1lf\n", 1e6);
	printf("%.7lf\n", 3.14e-5);
	printf("%le\n", 0.0000314);
	printf("%.2le\n", 0.0000314);

	return 0;
}

