
// 예제 3-7. char 배열에 문자열 복사
// 새로운 문자열 저장은 strcpy 함수 사용

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void){
	char fruit[20] = "strawberry";

	printf("%s\n", fruit);
	strcpy(fruit, "banana");
	printf("%s\n", fruit);
	
	return 0;
}
