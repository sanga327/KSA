
// 예제 12-2. char 포인터로 문자열 사용

#include <stdio.h>

int main(void){
	char *dessert = "apple";

	printf("오늘 후식은 %s입니다. \n", dessert);
	dessert = "banana";
	printf("내일 후식은 %s입니다. \n", dessert);

	return 0;
}
