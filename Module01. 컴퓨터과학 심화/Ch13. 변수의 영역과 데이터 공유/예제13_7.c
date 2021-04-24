
// 13-7. 주소를 전달하는 방법 - 포인터를 써서 변수의 값에 10을 더하는 경우

# include <stdio.h>

void add_ten(int *pa);

int main(void){
	int a = 10;
	add_ten(&a);
	printf("a: %d\n", a);
	return 0;
}
void add_ten(int *pa){
	*pa = *pa + 10;
}
