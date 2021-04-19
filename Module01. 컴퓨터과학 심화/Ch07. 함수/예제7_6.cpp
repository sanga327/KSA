
// 예제 7-6. 3번 실행되는 재귀호출 함수

#include <stdio.h>

void fruit(int count);

int main(void) {
	fruit(1);
	return 0;
}

void fruit(int count) {   // 호출 횟수를 매개변수에 저장
	printf("apple\n");
	if (count == 3) return;  // 호출 횟수가 3이면 반환하고 끝낸다.
	fruit(count + 1);    // 재호출 시 호출 횟수 1 증가
	printf("jam\n");
}


