

// 예제 11-5. scanf 함수의 반환값 활용 - 입력 문자의 아스키 코드 값 출력

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int res;
	char ch;

	while (1)
	{
		res = scanf("%c", &ch);
		if (res == -1) break;
		printf("%d ", ch);
	}
	return 0;
}
