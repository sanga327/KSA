
// 예제 12-4. gets 함수를 사용한 문자열 입력 - gets 함수로 한 줄의 문자열 입력

#include <stdio.h>

int main(void) {
	char str[80];

	printf("공백이 포함된 문자열 입력: ");
	gets_s(str, sizeof(str));
	printf("입력한 문자열은 %s입니다.", str);

	return 0;
}

