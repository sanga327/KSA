
// 예제 6-3. do~while문

#include <stdio.h>
int main(void){
	int a = 1; 
	
	do {
		a = a*2;
	} while(a<10);       // a가 10보다 작으면 9행을 반복
	printf("a: %d\n", a);  
	
	return 0;
}