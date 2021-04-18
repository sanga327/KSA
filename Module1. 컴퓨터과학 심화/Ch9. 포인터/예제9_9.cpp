
	
// 예제 9-9. 포인터 없이 두 변수의 값을 바꾸는 함수는?
// 변수의 값을 인수로 주는 경우

#include <stdio.h>

void swap(int x, int y);

int main(void) {
	int a = 10, b = 20;

	swap(a,b);
	printf("a: %d, b: %d\n", a,b);
			
	return 0;
}

void swap(int x, int y){
	int temp;
	temp = x;
	x=y;
	y = temp;
}
