
// 예제 13-4.
// auto 쓰나 안쓰나 지역변수라고 이해하면 딘다.
// static 붙이면 이 함수가 끝나도 지역변수도 정적으로 static화 시킨다.

#include <stdio.h>

void auto_func(void);
void static_func(void);

int main(void) {
	int i;
	printf("일반 지역 변수(auto)를 사용한 함수...\n");
	for (i = 0; i < 3; i++) {
		auto_func();
	}

	printf("정적 지역 변수(static)를 사용한 함수...\n");
	for (i = 0; i < 3; i++) {
		static_func();
	}
	return 0;
}

void auto_func(void) {
	auto a = 0;

	a ++ ;
	printf("%d\n", a);
}

void static_func(void) {
	static int a;
	a++;
	printf("%d\n", a);

}