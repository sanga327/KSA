#define _CRT_SECURE_NO_WARNINGS
#define FILENAME "C:\\Users\\user\\source\\repos\\module1_project1\\list.csv"
#define MAX 100
#define NUM 26 //수강생 수
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include "student.h"

Student* input();
int* index(char fir[NUM], char sec[NUM][MAX]);
void str_search();
void replace();
void print();

Student* pdata = input();
int main()
{

	char func[MAX];
	
	while (1)
	{
		printf("실행할 기능을 선택하세요.(출력, 검색, 수정, 종료)\n");
		scanf("%s", func);
		printf("\n");

		if (strcmp(func, "출력") == 0) print();
		else if (strcmp(func, "검색") == 0) str_search();
		else if (strcmp(func, "수정") == 0) replace();
		else if (strcmp(func, "종료") == 0) 
		{
			printf("종료되었습니다. \n");
			break;
		}

	}


	return 0;
}