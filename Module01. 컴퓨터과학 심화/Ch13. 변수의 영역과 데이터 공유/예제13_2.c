
// 예제 13-2. 블록 안에서 사용하는 지역 변수 - 블록 안에 지역 변수 사용하여 두 변수 교환

#include<stdio.h>

int main(void){
	int a= 10, b = 20;

	printf("교환 전 a와  b의 값: %d, %d\n", a, b);
	{
		int temp;
		temp = a;
		a = b;
		b = temp;
	}
	printf("교환 후 a와 b의 값: %d, %d\n", a, b);
	return 0;
}
