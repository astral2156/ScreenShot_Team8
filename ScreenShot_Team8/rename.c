//#include <Windows.h>
//
//void reName(LPCTSTR FileName) {			// �����̸� ����
//
//	LPCTSTR ReFileName;
//
//	printf("���� �̸� ����\n");
//	scanf("%s", &ReFileName);
//	//TEXT("C:\\Users\\wing9\\Desktop\\ScreenShot.bmp");
//	//LPCTSTR refilename = TEXT("c:\ScreenShot.bmp");
//
//
//	if (CopyFile(FileName, ReFileName, 0)) {
//		printf("�����̸��� ����Ǿ����ϴ�!\n");
//		printf("���� �����̸� : %s\n", ReFileName);
//	}
//	else {
//		printf("�����̸����� �����߻�\n");
//	}
//
//}
#include<Windows.h>
#include<stdio.h>
#include<io.h>
#include<conio.h>
typedef struct _finddata_t FILE_SEARCH;
LPTSTR Rename() {
	LPTSTR Name;
	char *tmp;
	char name[100];
	char str[50];
	int i;
	int index[2], cnt = 1, num = 0;
	FILE_SEARCH fd;
	long handle;
	int result = 1;
	handle = _findfirst(".\\*.bmp", &fd);
	if (handle == -1)
	{
		printf("There were no files.\n");
		return;
	}
	while (result != -1)
	{
		printf("File: %s\n", fd.name);
		tmp = fd.name;
		for (i = 0; i < strlen(fd.name); i++)
		{
			name[i] = *(tmp + i);
			if (*(tmp + i) == '(')
			{
				printf("dd");
				index[0] = i + 1;
				printf("[%d]\n", index[0]);
			}
			else if (*(tmp + i) == ')')
			{
				index[1] = i - 1;
				printf("[%d]\n", index[1]);
			}
			else
				printf("()�����\n");

		}
		name[i] = NULL;
		// ù��°���ϸ�
		/* �̰� while �� �ۿ��� �־��� ���� �ؿ�
		else�� ������ */
		if (strcmp(name, "screenshot.bmp") == 0)
		{
			printf("comt?");
			Name = "screenshot(1).bmp";
		}
		else
		{
			if (index[0] == index[1])
			{
				printf(">> %s\n", name);
				num = name[index[0]] - 48;
				printf("num: %d\n", num);
			}
			result = _findnext(handle, &fd);
		}
		cnt = num + 1;
		char NN = cnt + 48;
		printf("NN: %c\n", NN);
		_findclose(handle);
		return Name;
	}
