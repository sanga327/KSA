

// 예제 14-6. 포인터 배열 선언과 사용
// 포인터 배열로 여러 개의 문자열 출력

# include <stdio.h>

int main(void){
	const char *pary[5];
	int i;

	pary[0] = "dog"; 
	pary[1] = "elephant";
	pary[2] = "horse";
	pary[3] = "tiger";
	pary[4] = "lion";

	for(i=0; i<5; i++){
		printf("%s\n", pary[i]);
	}
	return 0;
}
