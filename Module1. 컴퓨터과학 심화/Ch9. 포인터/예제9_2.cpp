

// 예제 9-2. 포인터의 간접 참조 연산자: * 

#include <stdio.h>
int main(void) {
	int a;
	int *pa;
	
	pa = &a;
	*pa = 10;

	printf("포인터로 a값 출력: %d\n", *pa);
	printf("변수명으로 a값 출력: %d\n", a);

	return 0;
}
