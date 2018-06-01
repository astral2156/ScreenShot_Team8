#include <Windows.h>
#include<stdio.h>
#include<io.h>

typedef struct _finddata_t FILE_SEARCH;

char * reName(char *filePath, char *fileName) {
	char compareArr[100];
	int setForBreak = 0, sameName = 0;

	char pathForChecking[100]; // ����Ž�� ����
	strcpy(pathForChecking, filePath);
	strcat(pathForChecking, "*.bmp");

	FILE_SEARCH file;
	long handle;
	int result;

	while (setForBreak != 1)
	{
		setForBreak = 0;
		result = 1;
		sameName = 0;
		handle = _findfirst(pathForChecking, &file);

		printf("���ϸ��� �Է��ϼ��� : ");
		scanf("%s", fileName);

		strcpy(compareArr, fileName);
		strcat(compareArr, ".bmp");

		if (handle == -1)
		{
			printf("There were no files.\n");
			return fileName;
		}

		while (result != -1)
		{
			if (strcmp(compareArr, file.name) == 0)
			{

				printf("������ �̸��� �ֽ��ϴ�.\n");
				sameName = 1;
				break;
			}
			result = _findnext(handle, &file);
		}
		if (sameName != 1)
			setForBreak = 1;
	}

	_findclose(handle);

	printf("����� ���ϸ� : %s.bmp\n", fileName);
	strcat(fileName, ".bmp");
	return fileName;

}