#include <Windows.h>

void rePath(LPCTSTR FilePath) {			// ���ϰ�� ����
//void rePath(LPTSTR filename, LPTSTR filepath) {

	
	LPCTSTR ReFilePath;
	
	printf("���� ��� ����\n");
	scanf("%s", &ReFilePath);
	//TEXT("C:\\Users\\wing9\\Desktop\\ScreenShot.bmp");
	//LPCTSTR refilename = TEXT("c:\ScreenShot.bmp");

	// ���ϸ� ���� �Է�
	// LPCTSTR refilename;
	// scanf("%s", refilename);

	if (CopyFile(FilePath, ReFilePath, 0)) {
		printf("���ϰ�ΰ� ����Ǿ����ϴ�!\n");
		printf("���� ���ϰ�� : %s\n", ReFilePath);
	}

	else {
		printf("���ϰ�κ��� �����߻�\n");
	}

}