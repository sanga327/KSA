
// 예제 5-3. if~else if~else문

#include <stdio.h>
int main(void){
	int a = 0, b = 0;
	
	if (a>0) {
		b = 1;
	}
	else if (a ==0){
		b=2;
	}
	else {
		b=3;
	}
	printf("b: %d\n", b);
	return 0;
}
