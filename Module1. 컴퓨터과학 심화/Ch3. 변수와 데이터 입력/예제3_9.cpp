
// 예제 3-9. scanf 함수를 사용한 키보드 입력

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void){
	int a; 
	
	scanf("%d", &a);
	printf("입력된 값: %d\n", a);
	
	return 0;	
}

