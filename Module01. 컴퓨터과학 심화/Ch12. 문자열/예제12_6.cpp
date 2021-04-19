
// 예제 12-6. 표준 입력 함수의 버퍼 공유 문제 
// - 개행 문자로 인해 gets 함수가 입력을 못하는 경우

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int age;
	char name[20];

	printf("나이 입력: ");
	scanf("%d", &age);

	printf("이름 입력: ");
	gets_s(name, sizeof(name));

	printf("나이: %d, 이름: %s\n", age, name);

	return 0;
}
