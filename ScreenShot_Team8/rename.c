#include <Windows.h>
#include<stdio.h>
#include<io.h>
#include<stdlib.h>
#include<malloc.h>
#include "filename.h"
typedef struct _finddata_t FILE_SEARCH;

char * Rename(char *fName) {			// �����̸� ����
	int set = 0;
	char *ptr;
	FILE_SEARCH fd;
	long handle;
	int result = 1;
	handle = _findfirst(".\\*.*", &fd);

	printf("���� �̸� ����\n");
	scanf("%s", fName);
	char CompareArr[100];
	strcpy(CompareArr, fName);
	strcat(CompareArr, ".bmp");
	printf("comparearr :%s\n\n", CompareArr);
	if (handle == -1)
	{
		printf("There were no files.\n");
		return fName;
	}

	while (result != -1)
	{
		printf("File: %s\n", fd.name);
		
		if (strcmp(CompareArr, fd.name) == 0) 
		{
			set = 1;
			printf("������ �̸��� �ֽ��ϴ�. �⺻ ������ ����˴ϴ�.\n");
			fName[0] = NULL;
			ptr = SetFileName(fName);
			break;
		}
		result = _findnext(handle, &fd);
	}

	_findclose(handle);
	if (set)
		return ptr; // TODO : �ۿ� FileName=filename();�������
	else
	{
		printf("����� ���ϸ� : %s.bmp\n", fName);
		strcat(fName, ".bmp");
		return fName;
	}
}