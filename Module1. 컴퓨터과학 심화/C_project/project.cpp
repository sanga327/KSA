#define _CRT_SECURE_NO_WARNINGS
#define FILENAME "C:\\Users\\user\\source\\repos\\module1_project1\\list.csv"
#define MAX 100
#define NUM 26 //������ ��
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
		printf("������ ����� �����ϼ���.(���, �˻�, ����, ����)\n");
		scanf("%s", func);
		printf("\n");

		if (strcmp(func, "���") == 0) print();
		else if (strcmp(func, "�˻�") == 0) str_search();
		else if (strcmp(func, "����") == 0) replace();
		else if (strcmp(func, "����") == 0) 
		{
			printf("����Ǿ����ϴ�. \n");
			break;
		}

	}


	return 0;
}