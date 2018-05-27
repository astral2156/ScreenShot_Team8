/*
* This is free and unencumbered software released into the public domain.
*
* Anyone is free to copy, modify, publish, use, compile, sell, or
* distribute this software, either in source code form or as a compiled
* binary, for any purpose, commercial or non-commercial, and by any
* means.
*
* In jurisdictions that recognize copyright laws, the author or authors
* of this software dedicate any and all copyright interest in the
* software to the public domain. We make this dedication for the benefit
* of the public at large and to the detriment of our heirs and
* successors. We intend this dedication to be an overt act of
* relinquishment in perpetuity of all present and future rights to this
* software under copyright law.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
* OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
* OTHER DEALINGS IN THE SOFTWARE.
*
* For more information, please refer to <http://unlicense.org/>
*
* Contributors:
*   2016 djcj <djcj@gmx.de>
*/

/*
* screenshot-simple.c: Save a screenshot of the Windows desktop in .bmp format.
*  The image will be saved as "screenshot.bmp" in the current working directory.
*
*  All linker dependencies are specified explicitly in this file, so you can
*  compile screenshot-simple.exe by simply running:
*    cl screenshot-simple.c
*
*  To compile with GCC run:
*    gcc -Wall -Wextra -pedantic -O3 screenshot-simple.c -s -static -o screenshot-simple.exe -lgdi32
*/

#ifndef __GNUC__ 
#  pragma comment(lib, "user32.lib")
#  pragma comment(lib, "gdi32.lib")
#endif
//maybe-later : GNU��� ���� ����  gccȯ�濡�� �ʿ��ϴ� 
//���� �� �ڵ忡�� ���� ��� �����Ŷ� �����ȴ�.

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
	start();   // ����ȭ�� ȣ��

	int choice = 0;
	int sc = 0;

	char fName[100];
	char fName1[200];
	char FileName[100] = "screenshot.bmp";
	char FilePath[100] = ".\\save\\";
	char RFile[200] = "";

	strcat(RFile, FilePath);
	strcat(RFile, FileName);

	LPTSTR File = (LPSTR)(LPCTSTR)RFile;
	LPTSTR fFile;
	while (1)
	{
		printf("------------------------------------\n");
		printf("���� ����� Screenshot Image�� ����\n");
		printf("���ϸ� : %s\n\n", FileName);

		printf("0 : ��ũ�� ��  1 : ���ϸ� ����  2 : ���ϰ�� ���� 3 : ������\n");
		printf("�Է� : ");
		scanf("%d", &choice);

		switch (choice) {
		case 0:
			printf("0 : �⺻ �̸����� ��ũ�� ��  1. �̸� ���� �� ��ũ�� �� 2 : ���콺�� �̿��Ͽ� ��ũ�� ��\n");
			scanf("%d", &sc);
			switch (sc) {
			case 0: //Full
				strcpy(RFile, FilePath);
				strcat(RFile, SetFileName(FileName));

				File = (LPSTR)(LPCTSTR)RFile;

				if (takeScreenshot(File) == 0)
				{
					printf("Screenshot successfully saved.");
				}
				else
				{
					printf("Problem saving screenshot.");
				}
				break;

			case 1: // �̸� �� �� ���� �� ��ũ����
				strcpy(fName1, FilePath);
				strcat(fName1, Rename(fName));
				fFile = (LPSTR)(LPCTSTR)fName1;
				if (takeScreenshot(fFile) == 0)
				{
					printf("Screenshot successfully saved.\n");
				}
				else
				{
					printf("Problem saving screenshot.\n");
				}
				break;
			case 2: //Mouse
				strcpy(RFile, FilePath);
				strcat(RFile, SetFileName(FileName));

				File = (LPSTR)(LPCTSTR)RFile;

				if (takeScreenshot(File) == 0) {
					if (captureWithMouseDragging(RFile)) {
						printf("Screenshot successfully saved.");
					}
					else
					{
						printf("Problem saving screenshot.");
					}
				}
				else
				{
					printf("Problem saving screenshot.");
				}
				break;
			}
			break;
		case 1: // �⺻�̸� ����Ǵ� ���

			break;

		case 2:
			strcpy(FilePath, rePath(FilePath));
			strcpy(RFile, FilePath);
			strcat(RFile, FileName);

			LPTSTR File = (LPSTR)(LPCTSTR)RFile;
			break;
		case 3:
			printf("��ũ�� �� ���α׷��� �����մϴ�.");
			return 0;

		}

	}
	return 0;
}