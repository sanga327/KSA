
// 예제 10-5. 배열을 처리하는 함수
// 이 예제 참고해서 평균구하는 함수(예제8-2) 배열 형식으로 다시 만들 수 있다. 

#include <stdio.h>
void print_ary(int *pa);

int main(void) {
	int ary[5] = { 10,20,30,40,50 };
	print_ary(ary);
	return 0;
}

void print_ary(int *pa) {
	int i;
	for (i = 0; i < 5; i++) {
		printf("%d ", pa[i]);
	}
}
