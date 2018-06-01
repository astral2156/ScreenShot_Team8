#include<stdio.h>
#include<io.h>

typedef struct _finddata_t FILE_SEARCH;
char * setFileName(char *filePath, char *fileName)
{
	FILE_SEARCH file;
	long handle;
	int result = 1;

	char pathForChecking[100]; // ����Ž�� ����
	strcpy(pathForChecking, filePath);
	strcat(pathForChecking, "*.bmp");

	handle = _findfirst(pathForChecking, &file);

	char fileForm[] = "screenshot(n).bmp";
	char overlapName[100]; // ���ϸ� �ִ� ���� ����
	int overlapNameIdx = 0;
	char stdName[100] = "screenshot.bmp";
	int existBasic = 0; // screenshot.bmp�� �ִ��� . ������ 1

	if (handle == -1)
	{
		printf("There were no files.\n");
		return stdName;
	}

	while (result != -1)
	{
		if (strncmp(fileForm, file.name, 11) == 0) // 'screenshot('���� �������� �����ϸ�
		{
			overlapName[overlapNameIdx] = file.name[11]; // File�� number�� OverlapName�迭�� �ִ´�.  
			overlapNameIdx++;
		}

		if (strcmp(file.name, stdName) == 0) // screenshot.bmp�� ���� ����
		{
			existBasic = 1;
		}
		result = _findnext(handle, &file);
	}

	_findclose(handle);
	if (overlapNameIdx == 0)// num�迭�� �ƹ��͵� ������ ����.
	{
		if (existBasic == 0) // screenshot.bmp����.
			return stdName;
		
		else // screenshot.bmp�ִ�.
		{
			fileName = "screenshot(1).bmp";
			return fileName;
		}
	}
	else // num�迭 ä�����ִ�.
	{
		if (existBasic == 0) // screenshot.bmp����.
			return stdName;
		else //num �� ���ڵ��� �ְ� screenshot.bmp�� �ִ�. 
		{
			int i = 0;
			while (i != overlapNameIdx)
			{
				if (overlapName[i] + 1 != overlapName[i + 1])
				{
					memmove(fileForm + 11, fileForm + 12, strlen(fileForm) - 11);
					memmove(fileForm + 12, fileForm + 11, strlen(fileForm) - 11 + 1);
					fileForm[11] = overlapName[i] + 1;
					break;
				}
				i++;
			}
		}
	}


	strcpy(fileName, fileForm);

	return fileName;
}