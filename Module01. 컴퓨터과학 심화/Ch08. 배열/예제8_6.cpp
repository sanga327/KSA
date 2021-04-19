
// 예제 8-6. 문자열 전용 입출력 함수(gets, puts)

#include <stdio.h>

int main(void) {
	char str[80];

	printf("문자열 입력: ");
	gets_s(str);
	puts("입력될 문자열: ");
	puts(str);

	return 0;
}
