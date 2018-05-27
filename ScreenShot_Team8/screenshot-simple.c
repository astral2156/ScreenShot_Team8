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
#include "filename.h"
#include "Rename.h"


/*
C�� �̿��Ͽ� ��ũ���� ��� ���α׷��� ��� ���¼ҽ��̴�.
�⺻������ ��ũ������ ��� ���������� �˰� �ΰ������
�߰��ϴ°��� ��ǥ�̴�.
*/

int main(void)
{
	
/*	char FilePath[100] = ".\\Users\jungy\shot\ScreenShot_Team8\ScreenShot_Team8";
	char RFile[200] = "";
	strcat(RFile, FileName);
	strcat(RFile, FilePath);
*/	

//	LPTSTR File= (LPSTR)(LPCTSTR)RFile;

	char FileName[100]; // main->�Լ��� �Ѱ��� �迭
	char *ptr; // FileName ������ 
	//LPTSTR File; //takescreenshot�� �Ѱ��� ��
	
	int choice = 0;
	int sc = 0;
	start();	// ����ȭ�� ȣ��


	while (1)
	{
		printf("------------------------------------\n");
		printf("��ũ�� �� -> 1\n");
		printf("�����ϱ� -> 2\n");
		printf("������ -> 3\n");
		printf("------------------------------------\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			ptr = SetFileName(FileName);
			printf(": %s\n", ptr);
			LPTSTR File = (LPSTR)(LPCTSTR)ptr;
			printf("�������� ��ũ�������� �� File: %s\n", File);
			if (takeScreenshot(File) == 0)
			{
				printf("Screenshot successfully saved.\n");
			}
			else
			{
				printf("Problem saving screenshot.\n");
			}
			break;

		case 2:
			printf("------------------------------------\n");
			printf("���ϸ� ���� -> 1\n");
			printf("���ϰ�� ���� -> 2\n");
			printf("------------------------------------\n");
			scanf("%d", &sc);
			switch (sc) {
			case 1:
				ptr = Rename(FileName);
				File = (LPSTR)(LPCTSTR)ptr;
				if (takeScreenshot(File) == 0)
				{
					printf("Screenshot successfully saved.\n");
				}
				else
				{
					printf("Problem saving screenshot.\n");
				}
				break;
			case 2:
				break;
			}
			break;
		case 3:
			printf("��ũ�� �� ���α׷��� �����մϴ�.");
			return 0;
		}
		
	
		/*printf("���ϸ� : %s\n\n", FileName);

		//	printf("���ϸ� : %s\n���ϰ�� : %s\n\n", FileName, filepath);
		printf("0 : ��ũ�� ��  1 : ���ϸ� ����  2 : ���ϰ�� ���� 3 : ������\n");
		printf("�Է� : ");
		scanf("%d", &choice);

		switch (choice) {
		case 0:
			printf("0 : Full ScreenShot  1 : ScreenShot with mouse");
			scanf("%d", &sc);
			switch (sc) {
			case 0: // Full Screenshot
				if (takeScreenshot(File) == 0)
				{
					printf("Screenshot successfully saved.");
				}
				else
				{
					printf("Problem saving screenshot.");
				}
			}

		case 1: // ���ϸ� ����

			break;

		case 2:
			rePath(File);
			break;
		case 3:
			printf("��ũ�� �� ���α׷��� �����մϴ�.");
			return 0;

		}





	}*/
		
	}
	return 0;
}