

// 예제 12-11. 문자열 길이를 계산하는 strlen 함수 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char str1[80], str2[80];
	char *resp;

	printf("2개의 과일 이름 입력: ");
	scanf("%s%s", str1, str2);	
		if (strlen(str1) > strlen(str2))
			resp = str1;
		else
			resp = str2;
	printf("이름이 긴 과일은: %s\n", resp);

	return 0;
}