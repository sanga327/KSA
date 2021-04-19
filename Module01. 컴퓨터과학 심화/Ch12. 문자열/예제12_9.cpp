
// 예제 12-9. 원하는 개수의 문자만을 복사하는 strncpy 함수
// - strncpy 함수를 사용한 문자열 복사

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void){
	char str[20] = "mango tree";

	strncpy(str, "apple-pie", 5);
	printf("%s\n", str);
	
	return 0;
}
