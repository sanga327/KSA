
// 예제 5-5. else 결합 문제

#include <stdio.h>
int main(void){
	int a = 10, b = 20;

	if (a<0){
		if (b>0){
			printf("ok");
		}
	}
	else{
		printf("ok");
	}
	
	return 0;
}
