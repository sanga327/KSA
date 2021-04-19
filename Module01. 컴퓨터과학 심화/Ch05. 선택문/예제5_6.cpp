
// 예제 5-6. switch~case문

#include <stdio.h>
int main(void){
	int rank=2, m=0;

	switch(rank){
		case1:
			m = 300;
			break;
		case2:
			m = 200;
			break;
		case3:
			m = 100;
			break;
		default:
			m = 10;
			break;
	}
	printf("m: %d\n", m);

	return 0;
}

