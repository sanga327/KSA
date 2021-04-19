

// 예제 8-7. 문자열 끝에 널문자가 없다면?

#include <stdio.h>
int main(void) {
	char str[5];

	str[0] = '0';
	str[1] = 'K';
	printf("%s\n", str);

	return 0;

}


