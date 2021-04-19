// 예제 2-3. 제어 문자 출력
// \n: 줄바꿈, \t: 탭, \b: 백스페이스(출력 위치를 한 칸 왼쪽으로 옮김), \r: 맨 앞으로 이동, \a: 벨소리
#include <stdio.h>
int main(void)
{
	printf("Be happy\n");
	printf("12345678901234567890\n");
	printf("My\tfriend\n");
	printf("Goot\bd\tchange\n");
	printf("Cow\rW\a\n");  // 맨 앞으로 이동해 C를 W로 바꾸고 벨소리 내고 줄바꿈

	return 0;
}
