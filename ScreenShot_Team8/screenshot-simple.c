#include <Windows.h>
#include <stdio.h>
#include <string.h>

/*
C�� �̿��Ͽ� ��ũ���� ��� ���α׷��� ��� ���¼ҽ��̴�.
�⺻������ ��ũ������ ��� ���������� �˰� �ΰ������
�߰��ϴ°��� ��ǥ�̴�.
*/

int main(void)
{
	start();  

	int choice = 0;
	int sc = 0;

	char fName[100];
	char fName1[200];
	char FileName[100] = "screenshot.bmp";
	char FixedFileName[100] = "screenshot.bmp";
	char FilePath[100] = ".\\save\\";
	char RFile[200] = "";

	strcat(RFile, FilePath);
	strcat(RFile, FileName);

	LPTSTR File = (LPSTR)(LPCTSTR)RFile;
	LPTSTR fFile;

	while (1)
	{
		printf("------------------------------------\n\n");
		printf("���� ����� Screenshot Image�� ����\n");
		printf("���ϸ� : %s\n", FixedFileName);
		printf("���ϰ�� : %s\n", FilePath);
		printf("------------------------------------\n\n");

		printf("0 -> ��ũ�� ��\n1 -> ���ϰ�� ����\n2 -> ������\n\n");
		printf("�Է� -> ");
		scanf("%d", &choice);
		printf("\n");
		switch (choice) {
		case 0:
			printf("0 -> �⺻ �̸����� ��ũ�� ��\n1 -> �̸� ���� �� ��ũ�� ��\n2 -> ���콺�� �̿��Ͽ� ��ũ�� ��\n\n");
			printf("�Է� -> ");
			scanf("%d", &sc);
			printf("\n");
			switch (sc) {
			case 0:
				strcpy(RFile, FilePath);
				strcat(RFile, SetFileName(FileName));
				File = (LPSTR)(LPCTSTR)RFile;

				if (takeScreenshot(File) == 0)
				{
					printf("��ũ������ ���� �Ǿ����ϴ�.\n");
				}
				else
				{
					printf("��ũ���� ���忡 ������ ������ϴ�..\n");
				}
				break;

			case 1: 
				strcpy(fName1, FilePath);
				strcat(fName1, Rename(fName));
				fFile = (LPSTR)(LPCTSTR)fName1;
				if (takeScreenshot(fFile) == 0)
				{
					printf("��ũ������ ���� �Ǿ����ϴ�.\n");
				}
				else
				{
					printf("��ũ���� ���忡 ������ ������ϴ�..\n");
				}
				break;
			case 2:
				strcpy(RFile, FilePath);
				strcat(RFile, SetFileName(FileName));

				File = (LPSTR)(LPCTSTR)RFile;

				if (takeScreenshot(File) == 0) {
					if (captureWithMouseDragging(RFile)) {
						printf("��ũ������ ���� �Ǿ����ϴ�.\n");
					}
					else
					{
						printf("��ũ���� ���忡 ������ ������ϴ�..\n");
					}
				}
				else
				{
					printf("��ũ���� ���忡 ������ ������ϴ�..\n");
				}
				break;
			}
			break;
		case 1:
			strcpy(FilePath, rePath(FilePath));
			strcpy(RFile, FilePath);
			strcat(RFile, FileName);

			File = (LPSTR)(LPCTSTR)RFile;
			break;
		case 2:
			printf("��ũ�� �� ���α׷��� �����մϴ�.\n");
			return 0;

		}
		getchar();
		printf("���͸� ���� �ּ���\n");
		getchar();
		system("cls");

	}
	return 0;
}