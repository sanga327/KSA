
// 예제 12-3. scanf 함수를 사용한 문자열 입력

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char str[80];

	printf("문자열 입력: ");
	scanf("%s", str);
	printf("첫 번째 단어: %s\n", str);
	scanf("%s", str);
	printf("버퍼에 남아 있는 두 번째 단어: %s\n", str);

	return 0;
}