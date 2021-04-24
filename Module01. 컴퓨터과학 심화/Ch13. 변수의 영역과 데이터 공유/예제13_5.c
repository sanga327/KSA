
// 예제 13-5. 레지스터 변수를 반복문에 사용한 예
// 레지스터 변수는 웬만하면 사용할 일 없음. 임베디드에서 많이 사용한다.

#include <stdio.h>

int main(void){
	register int i;
	auto sum =0; 
	
	for (i=1; i<=10000; i++) {
		sum += i;
	}
	printf("%d\n", sum);
	return 0;
}