
// 예제 3-10. scanf 함수를 사용한 연속 입력

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void){
	int age;
	double height;
	
	printf("나이와 키를 입력하세요: ");
	scanf("%d%lf", &age, &height);
	printf("나이는 %d살, 키는 %.1lfcm입니다.\n", age, height);

	return 0;
	
}
