#include <Windows.h>
#include <string.h>

void reName(LPCTSTR FileName) {			// �����̸� ����

	LPCTSTR ReFileName;

	printf("���� �̸� ����\n");
	scanf("%s", &ReFileName);
	//TEXT("C:\\Users\\wing9\\Desktop\\ScreenShot.bmp");
	//LPCTSTR refilename = TEXT("c:\ScreenShot.bmp");


	if (CopyFile(FileName, ReFileName, 0)) {
		printf("�����̸��� ����Ǿ����ϴ�!\n");
		printf("���� �����̸� : %s\n", ReFileName);
	}
	else {
		printf("�����̸����� �����߻�\n");
	}

}
