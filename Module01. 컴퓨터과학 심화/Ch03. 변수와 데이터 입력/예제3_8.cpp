// 예제 3-8. const를 사용한 변수
// const를 사용한 변수는 초기값 수정 불가

#include <stdio.h>

int main(void){
	int income = 0;
	double tax;
	const double tax_rate = 0.12;
	
	income = 456;
	tax = income*tax_rate;
	printf("세금은: %.1lf입니다.\n", tax);

	return 0;
}
