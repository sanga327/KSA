
// 예제 3-4. unsigned를 잘못 사용한 경우 

#include <stdio.h>

int main(void){
	unsigned int a;
	a = 4294967295;
	printf("%d\n", a);
	a = -1;
	printf("%u\n", a);

	return 0;
}

// unsigned 자료형은 항상 양수만 저장하고 %u로 출력한다.