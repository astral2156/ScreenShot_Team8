#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include "reName.h"
#include "setFileName.h"
#include "mouseDraggingCapture.h"
/*
C�� �̿��Ͽ� ��ũ���� ��� ���α׷��� ��� ���¼ҽ��̴�.
�⺻������ ��ũ������ ��� ���������� �˰� �ΰ������
�߰��ϴ°��� ��ǥ�̴�.
*/

int main(void)
{
	startDisplay(); // ����ȭ�� ���
	
	int setChoice = 0; 
	int shotChoice = 0;
	
	char fileName[100] = "screenshot.bmp";
	char stdName[100] = "screenshot.bmp";
	char filePath[100] = ".\\save\\";
	
	char destFile[200] = "";

	strcat(destFile, filePath);
	strcat(destFile, fileName);

	LPTSTR file = (LPSTR)(LPCTSTR)destFile;

	while (1)
	{
		printf("------------------------------------\n\n");
		printf("���� ����� Screenshot Image�� ����\n");
		printf("���ϸ� : %s\n", fileName);
		printf("���ϰ�� : %s\n", filePath);
		printf("------------------------------------\n\n");

		printf("0 -> ��ũ�� ��\n1 -> ���ϰ�� ����\n2 -> ������\n\n");
		printf("�Է� -> ");
		scanf("%d", &setChoice);
		printf("\n");


		switch (setChoice) {
		case 0: // ��ũ����
			printf("0 -> �⺻ �̸����� ��ũ�� ��\n1 -> �̸� ���� �� ��ũ�� ��\n2 -> ���콺�� �̿��Ͽ� ��ũ�� ��\n3 -> �ڷΰ���\n\n");
			printf("�Է� -> ");
			scanf("%d", &shotChoice);
			printf("\n");
			switch (shotChoice) {
			case 0: // �⺻ �̸����� ��ũ���� 
				strcpy(destFile, filePath);
				strcat(destFile, setFileName(filePath, fileName));
				file = (LPSTR)(LPCTSTR)destFile;
				printf("File: %s\n", file);
				if (takeScreenshot(file) == 0)
				{
					printf("��ũ������ ���� �Ǿ����ϴ�.\n");
				}
				else
				{
					printf("��ũ���� ���忡 ������ ������ϴ�..\n");
				}
				break;

			case 1: // �̸� ���� �� ��ũ����
				strcpy(destFile, filePath);
				strcat(destFile, reName(filePath, fileName));
				file = (LPSTR)(LPCTSTR)destFile;
				if (takeScreenshot(file) == 0)
				{
					printf("��ũ������ ���� �Ǿ����ϴ�.\n");
				}
				else
				{
					printf("��ũ���� ���忡 ������ ������ϴ�..\n");
				}
				break;
			case 2: // ���콺�� �̿��Ͽ� ��ũ����
				strcpy(destFile, filePath);
				strcat(destFile, setFileName(filePath, fileName));

				file = (LPSTR)(LPCTSTR)destFile;

				if (takeScreenshot(file) == 0) {
					if (captureWithMouseDragging(destFile)) {
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
			case 3:
				break;
			}
			break;
		case 1: // ���ϰ�� ����
			strcpy(filePath, rePath(filePath));
			strcpy(destFile, filePath);
			strcat(destFile, fileName);

			file = (LPSTR)(LPCTSTR)destFile;
			break;
		case 2: // ����
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