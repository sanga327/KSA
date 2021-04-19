
// 예제 11-2. scanf 함수를 사용한 문자 입력 - 공백이나 제어 문자의 입력

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char ch1, ch2;
	scanf("%c%c", &ch1, &ch2);
	printf("[%c%c]", ch1, ch2);

	return 0;
}