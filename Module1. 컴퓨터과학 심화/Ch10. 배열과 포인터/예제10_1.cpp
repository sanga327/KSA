// 예제 10-1. 배열명에 정수 연산 수행하여 배열 요소 사용

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int ary[3];
	int i;

	*(ary + 0) = 10;
	*(ary + 1) = *(ary + 0) + 10;

	printf("세 번째 배열 요소에 키보드 입력: ");
	scanf("%d", ary + 2);

	for (i = 0; i < 3; i++) {
		printf("%5d", *(ary + i));  // print에서 바로 출력 가능
	}
	return 0;

}


