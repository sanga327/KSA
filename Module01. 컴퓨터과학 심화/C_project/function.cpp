#define _CRT_SECURE_NO_WARNINGS
#define FILENAME "C:\\Users\\user\\source\\repos\\module1_project1\\list.csv"
#define MAX 100
#define NUM 26 //수강생 수
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include "student.h"

extern Student* pdata;

Student* input() //CSV를 불러와 Student 구조체에 입력
{

	FILE* fp;
	Student data[MAX];
	Student* pdata;
	char str[MAX];
	char* pstr;
	int cnt = 0, i = 0;

	fp = fopen(FILENAME, "r");
	if (fp == NULL)
	{
		printf("failed to open the file\n"); //파일 로드 에러 처리
		exit(1);
	}

	for (i; i < NUM; i++)
	{
		pstr = fgets(str, sizeof(str), fp);
		if (cnt >= 0)
		{
			if (pstr == NULL) break; //메모장 한 줄을 입력받아옴
			sscanf(pstr, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,]", (data[i]).c1, (data[i]).c2, (data[i]).c3, (data[i]).c4, (data[i]).c5, (data[i]).c6);

		}
		else cnt++;
	}

	fclose(fp);
	pdata = data;

	return pdata;
}

int* index(char fir[MAX], char sec[NUM][MAX]) //sec에 있는 fir의 인덱스를 저장
{
	static int idx[NUM];
	int tmp = 0;

	for (int i = 0; i < NUM; i++)
	{
		if (strcmp(fir, sec[i]) == 0) // 같으면 저장하고 인덱스++
		{
			idx[tmp] = i;
			tmp++;
		}

	}
	idx[tmp] = 0;

	return idx;
}

void print()
{
	for (int i = 0; i < NUM; i++)  //조건식은 num*cols
	{
		printf("%s\t%s\t%s\t%s\t%s\t%s\t\n", &pdata[i].c1, &pdata[i].c2, &pdata[i].c3, &pdata[i].c4, &pdata[i].c5, &pdata[i].c6);
		//                                     기업           이름           성별          연락처       생년월일        좌석
	}
}



void str_search() //정보 검색
{
	char col[MAX], val[MAX];
	printf("검색할 항목을 입력하세요.(검색 항목 : 기업, 성함, 성별, 연락처, 생년월일, 좌석)\n");
	scanf("%s", col);
	printf("\n검색 내용을 입력하세요.\n");
	scanf("%s", val);

	char column[6][NUM] = { "기업","성함","성별","연락처","생년월일","좌석" }; //칼럼 배열
	char company[NUM][MAX]; //각각 구조체 항목의 배열
	char name[NUM][MAX];
	char sex[NUM][MAX];
	char phone[NUM][MAX];
	char birth[NUM][MAX];
	char seats[NUM][MAX];
	char* factor[6] = { *company, *name, *sex, *phone, *birth, *seats }; //2차원 배열의 포인터

	for (int i = 1; i < NUM; i++)
	{
		strcpy(company[i], pdata[i].c1); //각각 항목에 값을 저장
		strcpy(name[i], pdata[i].c2);
		strcpy(sex[i], pdata[i].c3);
		strcpy(phone[i], pdata[i].c4);
		strcpy(birth[i], pdata[i].c5);
		strcpy(seats[i], pdata[i].c6);
	}

	int* idx = 0;

	if (strcmp(col, column[0]) == 0) idx = index(val, company); //입력된 항목과 일치하면 검색어와 일치하는 인덱스를 가져오는 함수를 실행
	else if (strcmp(col, column[1]) == 0) idx = index(val, name);
	else if (strcmp(col, column[2]) == 0) idx = index(val, sex);
	else if (strcmp(col, column[3]) == 0) idx = index(val, phone);
	else if (strcmp(col, column[4]) == 0) idx = index(val, birth);
	else if (strcmp(col, column[5]) == 0) idx = index(val, seats);

	printf("%s\t\t%s\t%s\t%s\t\t%s\t%s\t\n", &pdata[0].c1, &pdata[0].c2, &pdata[0].c3, &pdata[0].c4, &pdata[0].c5, &pdata[0].c6);
	for (int i = 0; i < NUM; i++)//위에서 생성된 인덱스를 출력
	{
		if (idx[i] == 0) break;
		printf("%s\t%s\t%s\t%s\t%s\t\t%s\t\n", &pdata[idx[i]].c1, &pdata[idx[i]].c2, &pdata[idx[i]].c3, &pdata[idx[i]].c4, &pdata[idx[i]].c5, &pdata[idx[i]].c6);
	}
	return;
}

void replace()//찾아 고침
{
	char bef[MAX], aft[MAX];
	printf("찾을 단어와 수정할 단어를 입력하세요.\n찾을 단어: ");
	scanf("%s", bef);
	printf("\n수정할 단어: ");
	scanf("%s", aft);
	printf("\n");

	for (int i = 0; i < (NUM * 6); i++)
	{
		//printf("%s\n", &(*pdata).c1 + i);
		if (strcmp(bef, *(&(*pdata).c1 + i)) == 0) strcpy(*(&(*pdata).c1 + i), aft);
	}
	printf("수정이 완료되었습니다.\n");
}