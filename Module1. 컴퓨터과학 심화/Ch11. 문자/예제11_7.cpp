
// 예제 11-7. 버퍼의 내용을 지워야 하는 경우


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int num, grade;

	printf("학번 입력: ");
	scanf("%d", &num);
	getchar();
	printf("학점 입력: ");
	grade = getchar();
	printf("학번: %d, 학점: %c", num, grade);

	return 0;

}


