#include <Windows.h>
#include<stdio.h>
#include<io.h>
#include<stdlib.h>
#include<malloc.h>
#include "filename.h"
typedef struct _finddata_t FILE_SEARCH;

char Rename(char FileName) {			// �����̸� ����
	int set = 0;


	char ReFileName[100];
	char *ptr;
	FILE_SEARCH fd;
	long handle;
	int result = 1;
	handle = _findfirst(".\\*.*", &fd);

	printf("���� �̸� ����\n");
	scanf("%s", ReFileName);
	//TEXT("C:\\Users\\wing9\\Desktop\\ScreenShot.bmp");
	//LPCTSTR refilename = TEXT("c:\ScreenShot.bmp");

	if (handle == -1)
	{
		printf("There were no files.\n");
		return ReFileName;
	}

	while (result != -1)
	{
		printf("File: %s\n", fd.name);

		if (strcmp(fd.name, ReFileName) == 0) // screenshot.bmp�� ���� ����
		{
			set = 1;
			printf("������ �̸��� �ֽ��ϴ�. �⺻ ������ ����˴ϴ�.\n");
			ReFileName[0] = NULL;
			ptr=filename(ReFileName);
			break;
		}
		result = _findnext(handle, &fd);
	}

	_findclose(handle);
	if (set)
		return ptr; // TODO : �ۿ� FileName=filename();�������
	else
	{
		printf("����� ���ϸ� : %s\n", ReFileName);
		return ReFileName;
	}
}