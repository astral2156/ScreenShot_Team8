<<<<<<< HEAD
#include<Windows.h>
#include<stdio.h>
#include<io.h>
#include<stdlib.h>
//#include<malloc.h>

typedef struct _finddata_t FILE_SEARCH;
char * SetFileName(char *FileName)
{
	/*FILE_SEARCH fd;
	long handle;
	int result = 1;

	handle = _findfirst(".\\*.*", &fd);

	nameList = "filename.bmp";
	printf("namelist: %s\n", nameList);

	char *ptr;
	char arr[100];
	int i, *num;
	num = (int *)malloc(sizeof(int));
	if (handle == -1)
	{
	printf("There were no files.\n");
	return nameList;
	}

	while (result != -1)
	{
	printf("File: %s\n", fd.name);
	ptr = fd.name;
	for (i = 0; i < strlen(fd.name); i++)
	{
	arr[i] = *(ptr+i);
	}
	arr[i] = NULL;

	if (strncmp(arr, "filename(", 9) == 0)
	{
	printf(">>");
	num = arr[9] -48 + 1;
	printf("num:%d\n", num);
	num++;
	printf("num1:%d\n", num);
	}
	if (strcmp(arr, "screenshot.bmp") == 0)
	num = 1;

	result = _findnext(handle, &fd);
	}

	char brr[] = "screenshot(";
	strcat(brr, num);
	strcat(nameList, ").bmp");
	printf(">>>>>>>%s\n", nameList);
	_findclose(handle);



	return nameList;*/

	FILE_SEARCH fd;
	long handle;
	int result = 1;
	char fileform[] = "screenshot(n).bmp";
	handle = _findfirst(".\\*.*", &fd);

	char num[100]; // ���ϸ� �ִ� ���� ����
	int filenum = 0; // screenshot.bmp�� �ִ��� . ������ 1
	char NUM[10]; // itoa
	int idx = 0; //num[100]�� �ε���
	int i = 0; //�ݺ����� �� �ε��� 




	if (handle == -1)
	{
		printf("There were no files.\n");
		FileName = "screenshot.bmp";
		return FileName;
	}

	while (result != -1)
	{
		printf("File: %s\n", fd.name);

		if (strncmp(fileform, fd.name, 11) == 0) // 'screenshot('���� �������� �����ϸ�
		{
			num[idx] = fd.name[11]; //num�迭�� �־��ش�. 
			idx++;
		}

		if (strcmp(fd.name, "screenshot.bmp") == 0) // screenshot.bmp�� ���� ����
		{
			filenum = 1;
		}
		result = _findnext(handle, &fd);
	}

	_findclose(handle);
	if (idx == 0)// num�迭�� �ƹ��͵� ������ ����.
	{
		if (!filenum) // screenshot.bmp����.
		{
			printf("num�迭�� ���� screenshot.bmp�� ����.\n");
			FileName = "screenshot.bmp";
			printf("FileName::: %s\n", FileName);
			return FileName;
		}
		else // screenshot.bmp�ִ�.
		{
			printf("num�迭�� ���� screenshot.bmp�� �ִ�.\n");
			return "screenshot(1).bmp";
		}
	}
	else // num�迭 ä�����ִ�.
	{
		if (!filenum) // screenshot.bmp����.
		{
			printf("num�迭�� ���� �ִµ� screenshot.bmp�� ����.\n");
			FileName = "screenshot.bmp";
			return FileName;
		}
		else //num �� ���ڵ��� �ְ� screenshot.bmp�� �ִ�. 
		{
			printf("num�迭�� ���� �ִµ� screenshot.bmp�� �ִ�. ���ڷ� �ºκ�����\n");



			while (i != idx)
			{
				if (num[i] + 1 != num[i + 1])
				{
					memmove(fileform + 11, fileform + 12, strlen(fileform) - 11);
					memmove(fileform + 12, fileform + 11, strlen(fileform) - 11 + 1);
					fileform[11] = num[i] + 1;
					printf("fileform = namelist: %s\n", fileform);

					break;
				}
				i++;
			}
		}
	}


	strcpy(FileName, fileform);

	return FileName;
=======
#include<Windows.h>
#include<stdio.h>
#include<io.h>
#include<stdlib.h>

typedef struct _finddata_t FILE_SEARCH;
#include<malloc.h>
char filename(char *FileName)
{
	/*FILE_SEARCH fd;
	long handle;
	int result = 1;

	handle = _findfirst(".\\*.*", &fd);

	nameList = "filename.bmp";
	printf("namelist: %s\n", nameList);

	char *ptr;
	char arr[100];
	int i, *num;
	num = (int *)malloc(sizeof(int));
	if (handle == -1)
	{
	printf("There were no files.\n");
	return nameList;
	}

	while (result != -1)
	{
	printf("File: %s\n", fd.name);
	ptr = fd.name;
	for (i = 0; i < strlen(fd.name); i++)
	{
	arr[i] = *(ptr+i);
	}
	arr[i] = NULL;

	if (strncmp(arr, "filename(", 9) == 0)
	{
	printf(">>");
	num = arr[9] -48 + 1;
	printf("num:%d\n", num);
	num++;
	printf("num1:%d\n", num);
	}
	if (strcmp(arr, "screenshot.bmp") == 0)
	num = 1;

	result = _findnext(handle, &fd);
	}

	char brr[] = "screenshot(";
	strcat(brr, num);
	strcat(nameList, ").bmp");
	printf(">>>>>>>%s\n", nameList);
	_findclose(handle);



	return nameList;*/

	FILE_SEARCH fd;
	long handle;
	int result = 1;
	char fileform[] = "screenshot(n).bmp";
	handle = _findfirst(".\\*.*", &fd);

	char num[100]; // ���ϸ� �ִ� ���� ����
	int filenum = 0; // screenshot.bmp�� �ִ��� . ������ 1
	char NUM[10]; // itoa
	int idx = 0; //num[100]�� �ε���
	int i = 0; //�ݺ����� �� �ε��� 




	if (handle == -1)
	{
		printf("There were no files.\n");
		FileName = "screenshot.bmp";
		return FileName;
	}

	while (result != -1)
	{
		printf("File: %s\n", fd.name);

		if (strncmp(fileform, fd.name, 11) == 0) // 'screenshot('���� �������� �����ϸ�
		{
			num[idx] = fd.name[11]; //num�迭�� �־��ش�. 
			idx++;
		}

		if (strcmp(fd.name, "screenshot.bmp") == 0) // screenshot.bmp�� ���� ����
		{
			filenum = 1;
		}
		result = _findnext(handle, &fd);
	}

	_findclose(handle);
	if (idx == 0)// num�迭�� �ƹ��͵� ������ ����.
	{
		if (!filenum) // screenshot.bmp����.
		{
			printf("num�迭�� ���� screenshot.bmp�� ����.\n");
			FileName = "screenshot.bmp";
			return FileName;
		}
		else // screenshot.bmp�ִ�.
		{
			printf("num�迭�� ���� screenshot.bmp�� �ִ�.\n");
			return "screenshot(1).bmp";
		}
	}
	else // num�迭 ä�����ִ�.
	{
		if (!filenum) // screenshot.bmp����.
		{
			printf("num�迭�� ���� �ִµ� screenshot.bmp�� ����.\n");
			FileName = "screenshot.bmp";
			return FileName;
		}
		else //num �� ���ڵ��� �ְ� screenshot.bmp�� �ִ�. 
		{
			printf("num�迭�� ���� �ִµ� screenshot.bmp�� �ִ�. ���ڷ� �ºκ�����\n");



			while (i != idx)
			{
				if (num[i] + 1 != num[i + 1])
				{
					memmove(fileform + 11, fileform + 12, strlen(fileform) - 11);
					memmove(fileform + 12, fileform + 11, strlen(fileform) - 11 + 1);
					fileform[11] = num[i] + 1;
					printf("fileform = namelist: %s\n", fileform);

					break;
				}
				i++;
			}
		}
	}


	strcpy(FileName, fileform);

	return FileName;
>>>>>>> origin/master
}