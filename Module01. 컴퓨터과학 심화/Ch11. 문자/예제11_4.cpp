


// 예제 11-4. scanf 함수가 문자를 입력하는 과정 - 버퍼를 사용하는 문자 입력

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char ch;
	int i;

	for (i = 0; i < 3; i++) {
		scanf("%c", &ch);
		printf("%c", ch);
	}
	return 0;
}