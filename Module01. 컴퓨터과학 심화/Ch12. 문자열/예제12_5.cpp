
// 예제 12-5. fgets 함수를 사용한 문자열 입력

# include <stdio.h>

int main(void){
	char str[80];

	printf("공백이 포함된 문자열 입력: ");
	fgets(str, sizeof(str), stdin);
	printf("입력된 문자열은 %s입니다. \n", str);

	return 0;
}
