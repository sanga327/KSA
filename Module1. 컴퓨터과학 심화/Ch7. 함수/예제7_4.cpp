
// 예제 7-4. 매개변수와 반환값이 모두 없는 함수

#include <stdio.h>

void print_line(void); 

int main(void){
	print_line();
	printf("학번    이름    전공    학점\n");
	print_line();

	return 0;
}

void print_line(void){
	int i;

	for(i=0; i<50; i++){
		printf("-");
	}	
	printf("\n");
}
