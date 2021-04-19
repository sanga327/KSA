
// 예제 12-7. 문자열을 출력하는 puts, fputs 함수

#include <stdio.h>

int main(void){
	char str[80] = "apple juice";
	char *ps = "banana";

	puts(str);
	fputs(ps, stdout);
	puts("milk");

	return 0;
}
