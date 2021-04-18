
// 예제 3-4. unsigned를 잘못 사용한 경우 

#include <stdio.h>

int main(void){
	unsigned int a;
	a = 4294967295;
	printf("%d\n", a);
	a = -1;
// 예제 3-5. 유효숫자 확인

#include <stdio.h>

int main(void){
	float ft = 1.234567890123456789;
	double db = 1.234567890123456789;
	
	printf("float형 변수의 값: %.20f\n", ft);
	printf("double형 변수의 값: %.20lf\n", db);

	return 0;
	
}

	printf("%u\n", a);

	return 0;
}

// unsigned 자료형은 항상 양수만 저장하고 %u로 출력한다.