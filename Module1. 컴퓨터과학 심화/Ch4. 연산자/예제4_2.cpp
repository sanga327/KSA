
// 예제 4-2. 몫과 나머지를 구하는 연산

#include <stdio.h>
int main(void)
{
	double apple;   //실수
	int banana;    //정수
	int orange;    //정수

	apple = 5.0/2.0;
	banana = 5/2;
	orange = 5%2;

	printf("apple: %.1lf\n", apple);  // 실수와 실수의 나누기 연산
	printf("banana: %d\n", banana);  // 정수와 정수의 나누기 연산
	printf("orange: %d\n", orange);  // 정수와 정수의 나머지 연산
	
	return 0;
}
