#define _CRT_SECURE_NO_WARNINGS
#define FILENAME "C:\\Users\\user\\source\\repos\\module1_project1\\list.csv"
#define MAX 100
#define NUM 26 //������ ��
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include "student.h"

extern Student* pdata;

Student* input() //CSV�� �ҷ��� Student ����ü�� �Է�
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
		printf("failed to open the file\n"); //���� �ε� ���� ó��
		exit(1);
	}

	for (i; i < NUM; i++)
	{
		pstr = fgets(str, sizeof(str), fp);
		if (cnt >= 0)
		{
			if (pstr == NULL) break; //�޸��� �� ���� �Է¹޾ƿ�
			sscanf(pstr, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,]", (data[i]).c1, (data[i]).c2, (data[i]).c3, (data[i]).c4, (data[i]).c5, (data[i]).c6);

		}
		else cnt++;
	}

	fclose(fp);
	pdata = data;

	return pdata;
}

int* index(char fir[MAX], char sec[NUM][MAX]) //sec�� �ִ� fir�� �ε����� ����
{
	static int idx[NUM];
	int tmp = 0;

	for (int i = 0; i < NUM; i++)
	{
		if (strcmp(fir, sec[i]) == 0) // ������ �����ϰ� �ε���++
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
	for (int i = 0; i < NUM; i++)  //���ǽ��� num*cols
	{
		printf("%s\t%s\t%s\t%s\t%s\t%s\t\n", &pdata[i].c1, &pdata[i].c2, &pdata[i].c3, &pdata[i].c4, &pdata[i].c5, &pdata[i].c6);
		//                                     ���           �̸�           ����          ����ó       �������        �¼�
	}
}



void str_search() //���� �˻�
{
	char col[MAX], val[MAX];
	printf("�˻��� �׸��� �Է��ϼ���.(�˻� �׸� : ���, ����, ����, ����ó, �������, �¼�)\n");
	scanf("%s", col);
	printf("\n�˻� ������ �Է��ϼ���.\n");
	scanf("%s", val);

	char column[6][NUM] = { "���","����","����","����ó","�������","�¼�" }; //Į�� �迭
	char company[NUM][MAX]; //���� ����ü �׸��� �迭
	char name[NUM][MAX];
	char sex[NUM][MAX];
	char phone[NUM][MAX];
	char birth[NUM][MAX];
	char seats[NUM][MAX];
	char* factor[6] = { *company, *name, *sex, *phone, *birth, *seats }; //2���� �迭�� ������

	for (int i = 1; i < NUM; i++)
	{
		strcpy(company[i], pdata[i].c1); //���� �׸� ���� ����
		strcpy(name[i], pdata[i].c2);
		strcpy(sex[i], pdata[i].c3);
		strcpy(phone[i], pdata[i].c4);
		strcpy(birth[i], pdata[i].c5);
		strcpy(seats[i], pdata[i].c6);
	}

	int* idx = 0;

	if (strcmp(col, column[0]) == 0) idx = index(val, company); //�Էµ� �׸�� ��ġ�ϸ� �˻���� ��ġ�ϴ� �ε����� �������� �Լ��� ����
	else if (strcmp(col, column[1]) == 0) idx = index(val, name);
	else if (strcmp(col, column[2]) == 0) idx = index(val, sex);
	else if (strcmp(col, column[3]) == 0) idx = index(val, phone);
	else if (strcmp(col, column[4]) == 0) idx = index(val, birth);
	else if (strcmp(col, column[5]) == 0) idx = index(val, seats);

	printf("%s\t\t%s\t%s\t%s\t\t%s\t%s\t\n", &pdata[0].c1, &pdata[0].c2, &pdata[0].c3, &pdata[0].c4, &pdata[0].c5, &pdata[0].c6);
	for (int i = 0; i < NUM; i++)//������ ������ �ε����� ���
	{
		if (idx[i] == 0) break;
		printf("%s\t%s\t%s\t%s\t%s\t\t%s\t\n", &pdata[idx[i]].c1, &pdata[idx[i]].c2, &pdata[idx[i]].c3, &pdata[idx[i]].c4, &pdata[idx[i]].c5, &pdata[idx[i]].c6);
	}
	return;
}

void replace()//ã�� ��ħ
{
	char bef[MAX], aft[MAX];
	printf("ã�� �ܾ�� ������ �ܾ �Է��ϼ���.\nã�� �ܾ�: ");
	scanf("%s", bef);
	printf("\n������ �ܾ�: ");
	scanf("%s", aft);
	printf("\n");

	for (int i = 0; i < (NUM * 6); i++)
	{
		//printf("%s\n", &(*pdata).c1 + i);
		if (strcmp(bef, *(&(*pdata).c1 + i)) == 0) strcpy(*(&(*pdata).c1 + i), aft);
	}
	printf("������ �Ϸ�Ǿ����ϴ�.\n");
}