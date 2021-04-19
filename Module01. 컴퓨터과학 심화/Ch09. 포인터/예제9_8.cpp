

// 예제 9-8. 포인터 없이 두 변수의 값을 바꾸는 함수는?
// 다른 함수의 변수 사용하기 - 오류!

#include <stdio.h>

void swap(void);

int main(void) {
	int a = 10, b = 20;

	swap();
	printf("a: %d, b: %d\n", a, b);

	return 0;
}

void swap(void) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}
