
// 예제 7-1. 함수 정의

#include <stdio.h>

int sum(int x, int y);   // sum(int, int) 등으로 매개변수 생략 가능

int main(void){
	int a = 10, b =20;
	int result; 

	result = sum(a,b);
	printf("result: %d\n", result);

	return 0;

}

int sum(int x, int y){
	int temp;
	temp = x+y;
	return temp;
}

