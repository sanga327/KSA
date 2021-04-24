
// 예제 13-6. 값을 복사해서 전달하는 방법

#include <stdio.h>

void add_ten(int a);

int main(void){
	int a = 10;
	add_ten(a);
	printf("a: %d\n", a);
	return 0;
}

void add_ten(int a){
	a = a+10;
}

