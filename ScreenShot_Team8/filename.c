#include<Windows.h>
#include<stdio.h>
#include<io.h>
#include<stdlib.h>

typedef struct _finddata_t FILE_SEARCH;
char * SetFileName(char *FileName)
{
	FILE_SEARCH fd;
	long handle;
	int result = 1;
	char fileform[] = "screenshot(n).bmp";
	handle = _findfirst(".\\save\\*.bmp", &fd);

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
		if (strncmp(fileform, fd.name, 11) == 0) // 'screenshot('���� �������� �����ϸ�
		{
			num[idx] = fd.name[11]; //num�迭�� �־��ش�. 
			idx++;
		}

		if (strcmp(fd.name, "screenshot.bmp") == 0) // screenshot.bmp�� ���� ����
			filenum = 1;
		result = _findnext(handle, &fd);
	}

	_findclose(handle);
	if (idx == 0)// num�迭�� �ƹ��͵� ������ ����.
	{
		if (!filenum) // screenshot.bmp����.
		{
			FileName = "screenshot.bmp";
			return FileName;
		}
		else // screenshot.bmp�ִ�.
		{
			return "screenshot(1).bmp";
		}
	}
	else // num�迭 ä�����ִ�.
	{
		if (!filenum) // screenshot.bmp����.
		{
			FileName = "screenshot.bmp";
			return FileName;
		}
		else //num �� ���ڵ��� �ְ� screenshot.bmp�� �ִ�. 
		{
			while (i != idx)
			{
				if (num[i] + 1 != num[i + 1])
				{
					memmove(fileform + 11, fileform + 12, strlen(fileform) - 11);
					memmove(fileform + 12, fileform + 11, strlen(fileform) - 11 + 1);
					fileform[11] = num[i] + 1;
					break;
				}
				i++;
			}
		}
	}


	strcpy(FileName, fileform);

	return FileName;
}